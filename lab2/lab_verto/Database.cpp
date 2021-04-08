#include "Database.h"

bool Database::LoadFromFile(const char *file) {
	int poz;
	int age;
	int id;
	int salary;
	char f_Name[256];
	char l_Name[256];
	char depart[256];
	ifstream f(file);
	if (f.is_open()) {
		while (!f.eof()) {
			f >> poz;
			f.get();
			f >> id;
			f.get();
			f.getline(f_Name, 256, ';');
			f.getline(l_Name, 256, ';');
			f >> age;
			f.get();
			f.getline(depart, 256, ';');
			f >> salary;
			if (poz == 0) {
				Employee* e = new Employee(f_Name, l_Name, age, id);
				e->SetDepartment(depart);
				e->SetSalary(salary);
				employees.push_back(e);
			}
			else if (poz == 1) {
				Manager* m = new Manager(f_Name, l_Name, age, id);
				m->SetDepartment(depart);
				m->SetSalary(salary);
				employees.push_back(m);
			}
		}
		return true;
	}
	else
		return false;
}

void Database::ArrangeSubordinates() {
	vector<Person*>::iterator it = employees.begin();
	vector<Person*>::iterator itEml;
	while (it != employees.end()) {
		if (typeid(**it) == typeid(Manager)) { 
			string dept = dynamic_cast<Manager*>(*it)->GetDepartment();
			itEml = employees.begin();
			while (itEml != employees.end()) {
				if ((dept == dynamic_cast<Employee*>(*itEml)->GetDepartment()) && (typeid(**itEml) != typeid(Manager)))
					dynamic_cast<Manager*>(*it)->AddSubordinate(*itEml);
				++itEml;
			}
		}
		++it;
	}
}

Person* Database::HireEmployee(Person *p) {
	int poz;
	int age;
	int id;
	int salary;
	char f_Name[256];
	char l_Name[256];
	char depart[256];
	cout << "Employee type: ";
	cin >> poz;
	cout << "\nage: ";
	cin >> age;
	cout << "\nid: ";
	cin >> id;
	cout << "\nsalary: ";
	cin >> salary;
	cout << "\nFirst name: ";
	cin >> f_Name;
	cout << "\nLast name: ";
	cin >> l_Name;
	cout << "\nDepartment: ";
	cin >> depart;
	cout << endl;
	if (poz == 0) {
		Employee* e = new Employee(f_Name, l_Name, age, id);
		e->SetDepartment(depart);
		e->SetSalary(salary);
		employees.push_back(e);
	}
	else if (poz == 1) {
		Manager* m = new Manager(f_Name, l_Name, age, id);
		m->SetDepartment(depart);
		m->SetSalary(salary);
		employees.push_back(m);
	}
	return p;
}

void Database::DisplayDepartmentEmployees(string _department) {
	vector<Person*>::iterator it = employees.begin();
	while (it != employees.end()) {
		if (_department == dynamic_cast<Employee*>(*it)->GetDepartment()) {
			dynamic_cast<Employee*>(*it)->Display(true);
			cout << endl;
		}
		++it;
	}
}

bool Database::FireEmployee(int id) {
	vector<Person*>::iterator it = employees.begin();
	while (it != employees.end()) {
		if (typeid(**it) == typeid(Manager))
			dynamic_cast<Manager*>(*it)->DeleteSub(id);
		++it;
	}
	it = employees.begin();
	while (it != employees.end()) {
		if (id == dynamic_cast<Employee*>(*it)->GetId()) {
			employees.erase(it);
			return true;
		}
		++it;
	}
	return false;
}

void Database::DisplayAll() {
	vector<Person*>::iterator it = employees.begin(); 
	while (it != employees.end()) {
		if (typeid(**it) == typeid(Manager)) {  //manager
			dynamic_cast<Manager*>(*it)->Display(true);
			dynamic_cast<Manager*>(*it)->DisplaySubordinates();
		}
		if (typeid(**it) == typeid(Employee)) {  //employee
			dynamic_cast<Employee*>(*it)->Display(true);
		}
		cout << "\n\n";
		++it;
	}
}

vector<Person*> Database::SQL(const char* field, const char* cond, const char* value){
    if(field == NULL) throw runtime_error("ERROR: NULL in SQL(field ..)");
    if(cond == NULL) throw runtime_error("ERROR: NULL in SQL(..cond..)");
    if(value == NULL) throw runtime_error("ERROR: NULL in SQL(..value)");
    vector<Person*> empSQL;
    Employee* emp;
    Person* per;
    int valConvert = atoi(value);
    bool fieldCon = false, condCon = false;
    string str;
    str.assign(field);
    if(str.compare("age") != 0 && str.compare("salary") != 0)
        throw runtime_error("ERROR: uncorrect 'field' in SQL");
    if(str.compare("age") == 0) fieldCon = true;
    str.assign(cond);
    if(str.compare("le") != 0 && str.compare("ge") != 0)
        throw runtime_error("ERROR: uncorrect 'cond' in SQL");
    if(str.compare("le") == 0) condCon = true;
    for(int i = 1, count = employees.size(); i < count; i++){
        emp = dynamic_cast<Employee*>(employees.at(i));
        if(fieldCon == true){
            if(condCon == true){
                if(emp->GetAge() <= valConvert){
                    per = emp;
                    empSQL.push_back(per);
                }
            }
            else{
                if(emp->GetAge() >= valConvert){
                    per = emp;
                    empSQL.push_back(per);
                }
            }
        }
        else{
            if(condCon == true){
                if(emp->GetSalary() <= valConvert){
                    per = emp;
                    empSQL.push_back(per);
                }
            }
            else{
                if(emp->GetSalary() >= valConvert){
                    per = emp;
                    empSQL.push_back(per);
                }
            }
        }
    }
    return empSQL;
}








