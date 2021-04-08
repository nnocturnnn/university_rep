#include "Employee.h"

Employee::Employee(const Employee &e) {
	if (NULL != &e)
		*this = e;
}

Employee& Employee::operator = (const Employee &e) {
	if (NULL == &e || this == &e)
		return *this;
	f_name = e.f_name;
	l_name = e.l_name;
	age = e.age;
	id = e.id;
	department = e.department;
	salary = e.salary;
	return *this;
}

void Employee::SetSalary(int s) {
	salary = s;
}

void Employee::SetDepartment(string dept) {
	department = dept;
}

void Employee::SetId(int n) {
	id = n;
}

int Employee::GetId() {
	return id;
};

string Employee::GetDepartment() {
	return department;
}

int Employee::GetAge() {
	return age;
}

int Employee::GetSalary() {
	return salary;
}

string Employee::GetFName() {
	return f_name;
}

string Employee::GetLName() {
	return l_name;
}

void Employee::Display(bool) {
	cout << "Employee type: employee" << endl;
	cout << "id: " << id << endl;
	cout << f_name << " " << l_name << " age: " << age << " salary: " << salary << endl;
	cout << "department: " << department << endl;
}

