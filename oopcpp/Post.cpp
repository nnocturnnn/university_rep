#include "Post.h"

Post::Post(std::string name, int salary, Grade grade) : name(name),
     salary(salary), grade(grade){
}

Post::~Post() {
}

std::string Post::getName() {
	return this->name;
}
void  Post::setName(std::string name) {
	this->name = name;
}

int Post::getSalary() {
	return this->salary;
}
void Post::setSalary(int salary) {
	this->salary = salary;
}

Grade Post::getGrade() {
	return this->grade;
}
void Post::setGrade(Grade grade) {
	this->grade = grade;
}

