#pragma once
#include "Manager.h"
#include <iostream>
#include <fstream>
#include <vector>

class Database {
public:
	Database() {};
	~Database() {};
	bool LoadFromFile(const char *file);
	void ArrangeSubordinates();
	Person* HireEmployee(Person *p);
	void DisplayDepartmentEmployees(string _department);
	bool FireEmployee(int id);
	void DisplayAll();
	vector<Person*> Database::SQL(const char* field, const char* cond, const char* value);

private:
	vector<Person*> employees;
};
