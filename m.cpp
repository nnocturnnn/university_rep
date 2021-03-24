#ifndef __PROGTEST__
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;
#endif /* __PROGTEST__ */

class CCarList
{
public:
    CCarList( void ) {}
    CCarList( vector<string> p, vector<unsigned int> v ): plates(p), vins(v) {}
    string         RZ           ( void ) const;
    unsigned int   VIN          ( void ) const;
    bool           AtEnd        ( void ) const;
    void           Next         ( void );
    
    CCarList& operator = ( const CCarList & );
    friend ostream& operator << ( ostream &, const CCarList & );
private:
    vector<string> plates;
    vector<unsigned int> vins;
};

class CPersonList
{
public:
    CPersonList( void ) {}
    CPersonList( vector<string> n, vector<string> s ): names(n), surnames(s) {}
    string         Name         ( void ) const;
    string         Surname      ( void ) const;
    bool           AtEnd        ( void ) const;
    void           Next         ( void );
    
    CPersonList& operator = ( const CPersonList & );
    friend ostream& operator << ( ostream &, CPersonList & );
private:
    vector<string> names;
    vector<string> surnames;
};


class CRegister
{
public:
    CRegister    ( void ) {}
    ~CRegister    ( void );
    bool           AddCar       ( const string    & rz,
                                 const string    & name,
                                 const string    & surname );
    bool           DelCar       ( const string    & rz );
    bool           DelCar       ( unsigned int      vin );
    bool           Transfer     ( const string    & rz,
                                 const string    & nName,
                                 const string    & nSurname );
    bool           Transfer     ( unsigned int      vin,
                                 const string    & nName,
                                 const string    & nSurname );
    CCarList       ListCars     ( const string    & name,
                                 const string    & surname ) const;
    int            CountCars    ( const string    & name,
                                 const string    & surname ) const;
    CPersonList     ListOwners   ( const string    & RZ ) const;
    int            CountOwners  ( const string    & RZ ) const;
    CPersonList     ListOwners   () const;
    int            CountOwners  ( unsigned int      vin ) const;
    
    
    friend ostream& operator << ( ostream &, const CRegister & );

private:
    struct Person;
    struct CCar {
        CCar( string rz = "", unsigned int vin = 0, Person *owner = NULL ): rz(rz), vin(vin), owner(owner) {}
        bool operator == ( const CCar & );
        
        string rz;
        unsigned int vin;
        vector<Person *> owners;
        Person *owner;
    };
    
    struct Person {
        Person( string name, string surname ): name(name), surname(surname) {}
        bool operator == ( const Person & ) const;
        bool operator < ( const Person & ) const;
        
        string name;
        string surname;
        vector<CCar *> plates;
        vector<CCar *> vins;
    };
    
    vector<Person *> m_ListByNames;
    vector<CCar *> m_ListByRZ;
    vector<CCar *> m_ListByVin;
    
    bool contentsRZ( const string & ) const;
    bool contentsVin( unsigned int ) const;
    void addPersonRZ( Person &, CCar * );
    void addPersonVin( Person &, CCar *);
    void removePersonCar( const CCar & );
    void DelCar( CCar & );
};

/*
 * CCarList class definition
 ------------------------------------------------------------------ */
string CCarList::RZ( void ) const {
    return plates.back();
}

unsigned int CCarList::VIN( void ) const {
    return vins.back();
}

bool CCarList::AtEnd( void ) const {
    return vins.rbegin() == vins.rend();
}

void CCarList::Next( void ) {
    if ( plates.size() != 0 ) {
        plates.pop_back();
        vins.pop_back();
    }
}

/* PRIVATE */
CCarList& CCarList::operator = ( const CCarList &n ) {
    if( this == &n ) return *this;
    
    plates = n.plates;
    vins   = n.vins;
    
    return *this;
}


/**
 * CPersonList class definition
 ------------------------------------------------------------------ */
string CPersonList::Name( void ) const {
    return names.back();
}

string CPersonList::Surname( void ) const {
    return surnames.back();
}

bool CPersonList::AtEnd( void ) const {
    return names.rend() == names.rbegin();
}

void CPersonList::Next( void ) {
    if( names.size() != 0 ) {
        names.pop_back();
        surnames.pop_back();
    }
}

CPersonList& CPersonList::operator = ( const CPersonList &n ) {
    if( this == &n ) return *this;
    
    names = n.names;
    surnames = n.surnames;
    
    return *this;
}

/* PRIVATE */


/**
 * CRegister class definition
 ------------------------------------------------------------------ */
CRegister::~CRegister( void ) {
    for ( auto &n : m_ListByNames ) delete n;
    for ( auto &r : m_ListByRZ ) delete r;
}

bool CRegister::AddCar( const string &rz, const string &name, const string &surname) {
    if ( contentsRZ( rz ) ) return  false;
    
    Person *owner = new Person( name, surname );
    CCar   *car   = new CCar(rz);
    auto   oIt    = lower_bound( m_ListByNames.begin(), m_ListByNames.end(), owner, [] ( const Person *l, const Person *r ) { return *l < *r; } );
    
    if ( oIt != m_ListByNames.end() && *(*oIt) == *owner ) { // majitel uz existuje
        car->owner = *oIt;
        car->owners.push_back( *oIt );
        addPersonRZ( *(*oIt), car );
        addPersonVin( *(*oIt), car );
        delete owner;
    } else { // novy majitel
        m_ListByNames.insert( oIt, owner );
        car->owner = owner;
        car->owners.push_back( owner );
        owner->plates.push_back( car );
        owner->vins.push_back( car );
    }
    
    auto rIt = lower_bound( m_ListByRZ.begin(), m_ListByRZ.end(), car, [] ( const CCar *l, const CCar *r ) { return l->rz < r->rz; } );
    m_ListByRZ.insert( rIt, car );
    
    auto vIt = lower_bound( m_ListByVin.begin(), m_ListByVin.end(), car, [] ( const CCar *l, const CCar *r) { return l->vin < r->vin; } );
    m_ListByVin.insert( vIt, car );
    
    return true;
}

bool CRegister::DelCar( const string &rz ) {
    if ( ! contentsRZ( rz ) ) return false;
    
    CCar tmpCar( rz );
    auto rIt = lower_bound( m_ListByRZ.begin(), m_ListByRZ.end(), &tmpCar, [] ( const CCar *l, const CCar *r ) { return l->rz < r->rz; } );
    
    CCar *del  = (*rIt);
    tmpCar.vin = del->vin;
    DelCar( *del );
    
    delete del;
    return true;
}

bool CRegister::DelCar( unsigned int vin ) {
    if ( ! contentsVin( vin ) ) return false;
    
    CCar tmpCar( "", vin );
    auto vIt     = lower_bound( m_ListByVin.begin(), m_ListByVin.end(), &tmpCar, [] ( const CCar *l, const CCar *r ) { return l->vin < r->vin; } );
    
    return DelCar( (*vIt)->rz );
}

bool CRegister::Transfer( const string &rz, const string &name, const string &surname ) {
    CCar tmpCar( rz );
    auto cIt = lower_bound( m_ListByRZ.begin(), m_ListByRZ.end(), &tmpCar, [] ( const CCar *l, const CCar *r ) { return l->rz < r->rz; } );
    
    if( cIt != m_ListByRZ.end() && (**cIt).rz == tmpCar.rz ) { // existujici auto
        Person *owner = new Person( name, surname );
        
        if ( *((*cIt)->owner) == *owner ) { // stejny majitel
            delete owner;
            return false;
        }

        auto oIt = lower_bound( m_ListByNames.begin(), m_ListByNames.end(), owner, [] ( const Person *l, const Person *r ) { return *l < *r; } );
        removePersonCar( **cIt );
        
        if ( oIt != m_ListByNames.end() && **oIt == *owner ) { // existujici majitel
            (*cIt)->owner = *oIt;
            (*cIt)->owners.push_back( *oIt );
            addPersonRZ( **oIt, *cIt);
            addPersonVin( **oIt, *cIt);
            delete owner;
        } else { // novy majitel
            (*cIt)->owner = owner;
            (*cIt)->owners.push_back( owner );
            m_ListByNames.insert( oIt, owner );
            owner->plates.push_back( *cIt );
            owner->vins.push_back( *cIt );
        }
        
        return true;
    }
    return false;
}

bool CRegister::Transfer( unsigned int vin, const string &name, const string &surname ) {
    if ( ! contentsVin( vin) ) return false;
    
    CCar tmp( "", vin );
    auto it = lower_bound(m_ListByVin.begin(), m_ListByVin.end(), &tmp, [] ( const CCar *l, const CCar *r) { return l->vin < r->vin; } );
    
    return Transfer( (*it)->rz, name, surname );
}

CCarList CRegister::ListCars( const string &name, const string &surname ) const {
    Person p( name, surname );
    vector<string> plates;
    vector<unsigned int> vins;
    auto it = lower_bound( m_ListByNames.begin(), m_ListByNames.end(), &p, [] ( const Person *l, const Person *r ) { return *l < *r; } );
    
    if( it != m_ListByNames.end() && **it == p ) {
        for( auto &c : (*it)->vins ) {
            plates.push_back( c->rz );
            vins.push_back( c->vin );
        }
    }
    
    return CCarList( plates, vins );
}

int CRegister::CountCars( const string &name, const string &surname ) const {
    Person p( name, surname );
    auto it = lower_bound( m_ListByNames.begin(), m_ListByNames.end(), &p, [] ( const Person *l, const Person *r ) { return *l < *r; } );
    
    return ( it != m_ListByNames.end() && **it == p ) ? (int) (*it)->plates.size() : 0;
}

CPersonList CRegister::ListOwners( const string &rz ) const {
    vector<string> names;
    vector<string> surnames;
    CCar c( rz );
    auto it = lower_bound( m_ListByRZ.begin(), m_ListByRZ.end(), &c, [] ( const CCar *l, const CCar *r ) { return l->rz < r->rz; } );
    
    if ( it != m_ListByRZ.end() && (*it)->rz == c.rz ) {
        for ( auto &o : (*it)->owners ) {
            names.push_back( o->name );
            surnames.push_back( o->surname );
        }
    }
    
    return CPersonList( names, surnames );
}

int CRegister::CountOwners( const string &rz ) const {
    CCar c( rz );
    auto it = lower_bound( m_ListByRZ.begin(), m_ListByRZ.end(), &c, [] ( const CCar *l, const CCar *r ) { return l->rz < r->rz; } );
    return ( it != m_ListByRZ.end() && (*it)->rz == c.rz ) ? (int) (*it)->owners.size() : 0;
}

CPersonList CRegister::ListOwners() const {
    vector<string> names;
    vector<string> surnames;
    CCar c( "");
    auto it = lower_bound( m_ListByVin.begin(), m_ListByVin.end(), &c, [] ( const CCar *l, const CCar *r ) { return l->vin < r->vin; } );
    
    if ( it != m_ListByVin.end() ) {
        for ( auto &o : (*it)->owners ) {
            names.push_back( o->name );
            surnames.push_back( o->surname );
        }
    }
    
    return CPersonList( names, surnames );
}

int CRegister::CountOwners( unsigned int vin ) const {
    CCar c( "", vin );
    auto it = lower_bound( m_ListByVin.begin(), m_ListByVin.end(), &c, [] ( const CCar *l, const CCar *r ) { return l->vin < r->vin; } );
    return ( it != m_ListByVin.end() && (*it)->vin == c.vin ) ? (int) (*it)->owners.size() : 0;
}

ostream& operator << ( ostream &os, const CRegister &c ) {
    cout << "Persons" << endl;
    
    for ( auto &p : c.m_ListByNames ) cout << p->surname << " " << p->name << ", no. of p: " << p->plates.size() << ", v: " << p->vins.size() << endl;
    
    cout << "Plates" << endl;
    
    for ( auto &p : c.m_ListByRZ ) cout << p->rz << " " << p->owner->surname << " " << p->owner->name << endl;
    
    return os;
}

/* PRIVATE */
bool CRegister::contentsRZ( const string &rz ) const{
    CCar tmp( rz );
    return binary_search( m_ListByRZ.begin(), m_ListByRZ.end(), &tmp, [] ( const CCar *l, const CCar *r ) { return l->rz < r->rz; } );
}

bool CRegister::contentsVin( unsigned int vin ) const {
    CCar tmp( "", vin );
    return binary_search( m_ListByVin.begin(), m_ListByVin.end(), &tmp, [] ( const CCar *l, const CCar *r ) { return l->vin < r->vin; } );
}

void CRegister::DelCar( CCar &c ) {
    removePersonCar( c );
    
    auto rIt  = lower_bound( m_ListByRZ.begin(), m_ListByRZ.end(), &c, [] ( const CCar *l, const CCar *r ) { return l->rz < r->rz; } );
    auto vIt  = lower_bound( m_ListByVin.begin(), m_ListByVin.end(), &c, [] ( const CCar *l, const CCar *r ) { return l->vin < r->vin; } );
    
    if( rIt  != m_ListByRZ.end() && **rIt == c )  m_ListByRZ.erase( rIt );
    if( vIt  != m_ListByVin.end() && **vIt == c ) m_ListByVin.erase( vIt );
}


void CRegister::addPersonRZ( Person &p, CCar *c ) {
    auto it = lower_bound( p.plates.begin(), p.plates.end(), c, [] ( const CRegister::CCar *l, const CRegister::CCar *r ) { return l->rz < r->rz; } );
    p.plates.insert( it, c );
}

void CRegister::addPersonVin( Person &p, CCar *c ) {
    auto it = lower_bound( p.vins.begin(), p.vins.end(), c, [] ( const CRegister::CCar *l, CRegister::CCar *r ) { return l->vin < r->vin; } );
    p.vins.insert( it, c );
}

void CRegister::removePersonCar( const CCar &c ) {
    auto orIt = lower_bound( c.owner->plates.begin(), c.owner->plates.end(), &c, [] ( const CCar *l, const CCar *r ) { return l->rz < r->rz; } );
    auto ovIt = lower_bound( c.owner->vins.begin(), c.owner->vins.end(), &c, [] ( const CCar *l, const CCar *r ) {
        return l->vin < r->vin; } );
    
    if( orIt != c.owner->plates.end() && **orIt == c ) c.owner->plates.erase( orIt );
    if( ovIt != c.owner->vins.end() && **ovIt == c ) c.owner->vins.erase( ovIt );
}

bool CRegister::Person::operator == ( const Person &p ) const {
    return this->name == p.name && this->surname == p.surname;
}

bool CRegister::Person::operator < ( const Person &p ) const {
    if( this->surname == p.surname ) return this->name < p.name;
    return this->surname < p.surname;
}

bool CRegister::CCar::operator == ( const CCar &c ) {
    return this->rz == c.rz && this->vin == c.vin;
}

bool checkPerson           ( CRegister    & r,
                             const string & name,
                             const string & surname,
                             vector<string> result )
{
  for ( CCarList l = r . ListCars ( name, surname ); ! l . AtEnd (); l . Next () )
  {
    auto pos = find ( result . begin (), result . end (), l . RZ () ); 
    if ( pos == result . end () )
      return false;
    result . erase ( pos );
  }
  return result . size () == 0;
}


#ifndef __PROGTEST__

int main ( void )
{
  CRegister b1;
  assert ( b1 . AddCar ( "ABC-12-34", "John", "Smith" ) == true );
  assert ( b1 . AddCar ( "ABC-32-22", "John", "Hacker" ) == true );
  assert ( b1 . AddCar ( "XYZ-11-22", "Peter", "Smith" ) == true );
  assert ( b1 . CountCars ( "John", "Hacker" ) == 1 );
  assert ( checkPerson ( b1, "John", "Hacker", { "ABC-32-22" } ) );
  assert ( b1 . Transfer ( "XYZ-11-22", "John", "Hacker" ) == true );
  assert ( b1 . AddCar ( "XYZ-99-88", "John", "Smith" ) == true );
  assert ( b1 . CountCars ( "John", "Smith" ) == 2 );
  assert ( checkPerson ( b1, "John", "Smith", { "ABC-12-34", "XYZ-99-88" } ) );
  assert ( b1 . CountCars ( "John", "Hacker" ) == 2 );
  assert ( checkPerson ( b1, "John", "Hacker", { "ABC-32-22", "XYZ-11-22" } ) );
  assert ( b1 . CountCars ( "Peter", "Smith" ) == 0 );
  assert ( checkPerson ( b1, "Peter", "Smith", {  } ) );
  assert ( b1 . Transfer ( "XYZ-11-22", "Jane", "Black" ) == true );
  assert ( b1 . CountCars ( "Jane", "Black" ) == 1 );
  assert ( checkPerson ( b1, "Jane", "Black", { "XYZ-11-22" } ) );
  assert ( b1 . CountCars ( "John", "Smith" ) == 2 );
  assert ( checkPerson ( b1, "John", "Smith", { "ABC-12-34", "XYZ-99-88" } ) );
  assert ( b1 . DelCar ( "XYZ-11-22" ) == true );
  assert ( b1 . CountCars ( "Jane", "Black" ) == 0 );
  assert ( checkPerson ( b1, "Jane", "Black", {  } ) );
  assert ( b1 . AddCar ( "XYZ-11-22", "George", "White" ) == true );
  CPersonList i1 = b1.ListOwners ();
  assert ( ! i1 . AtEnd () && i1 . Surname () == "Hacker" && i1 . Name () == "John" );
  assert ( checkPerson ( b1, "John", "Hacker", { "ABC-32-22" } ) );
  i1 . Next ();
  assert ( ! i1 . AtEnd () && i1 . Surname () == "Smith" && i1 . Name () == "John" );
  assert ( checkPerson ( b1, "John", "Smith", { "ABC-12-34", "XYZ-99-88" } ) );
  i1 . Next ();
  assert ( ! i1 . AtEnd () && i1 . Surname () == "White" && i1 . Name () == "George" );
  assert ( checkPerson ( b1, "George", "White", { "XYZ-11-22" } ) );
  i1 . Next ();
  assert ( i1 . AtEnd () );

  CRegister b2;
  assert ( b2 . AddCar ( "ABC-12-34", "John", "Smith" ) == true );
  assert ( b2 . AddCar ( "ABC-32-22", "John", "Hacker" ) == true );
  assert ( b2 . AddCar ( "XYZ-11-22", "Peter", "Smith" ) == true );
  assert ( b2 . AddCar ( "XYZ-11-22", "Jane", "Black" ) == false );
  assert ( b2 . DelCar ( "AAA-11-11" ) == false );
  assert ( b2 . Transfer ( "BBB-99-99", "John", "Smith" ) == false );
  assert ( b2 . Transfer ( "ABC-12-34", "John", "Smith" ) == false );
  assert ( b2 . CountCars ( "George", "White" ) == 0 );
  assert ( checkPerson ( b2, "George", "White", {  } ) );
  CPersonList i2 = b2.ListOwners();
  assert ( ! i2 . AtEnd () && i2 . Surname () == "Hacker" && i2 . Name () == "John" );
  assert ( checkPerson ( b2, "John", "Hacker", { "ABC-32-22" } ) );
  i2 . Next ();
  assert ( ! i2 . AtEnd () && i2 . Surname () == "Smith" && i2 . Name () == "John" );
  assert ( checkPerson ( b2, "John", "Smith", { "ABC-12-34" } ) );
  i2 . Next ();
  assert ( ! i2 . AtEnd () && i2 . Surname () == "Smith" && i2 . Name () == "Peter" );
  assert ( checkPerson ( b2, "Peter", "Smith", { "XYZ-11-22" } ) );
  i2 . Next ();
  assert ( i2 . AtEnd () );

  return 0;
}

#endif /* __PROGTEST__ */