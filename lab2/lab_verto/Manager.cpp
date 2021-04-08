#include "Manager.h"

Manager::Manager(const Manager &m) {
	if (NULL != &m)
		*this = m;
}

Manager& Manager::operator = (const Manager &m) {
	if (NULL == &m || this == &m)
		return *this;
	f_name = m.f_name;
	l_name = m.l_name;
	age = m.age;
	id = m.id;
	subordinates = m.subordinates;
	return *this;
}

void Manager::DeleteSub(int id) {
	list<Person *>::iterator it = subordinates.begin();
	while (it != subordinates.end()) {
		if (id == dynamic_cast<Employee*>(*it)->GetId()) {
			subordinates.remove(*it);
			break;
		}
		++it;
	}
};

void Manager::Display(bool) {
	cout << "Employee type: manager" << endl;
	cout << "id: " << id << endl;
	cout << f_name << " " << l_name << " age: " << age << " salary: " << salary << endl;
	cout << "department: " << department << endl;
	cout << "Subordinates: " << endl;
}

Person* Manager::AddSubordinate(Person *p) {
	subordinates.push_back(p);
	return p;
}

void Manager::DisplaySubordinates() {
	list<Person *>::iterator it = subordinates.begin();
	if (subordinates.size() == 0)
		cout << "\t\tnone" << endl;
	while (it != subordinates.end()) {
		cout << "\t\tEmployment type: employee\n";
		cout << "\t\tid: " << dynamic_cast<Employee*>(*it)->GetId() << endl;
		cout << "\t\t" << dynamic_cast<Employee*>(*it)->GetFName() << " " \
			<< dynamic_cast<Employee*>(*it)->GetLName() << " age: " \
			<< dynamic_cast<Employee*>(*it)->GetAge() << " salary: " \
			<< dynamic_cast<Employee*>(*it)->GetSalary() << "\n\n";
		++it;
	}
}