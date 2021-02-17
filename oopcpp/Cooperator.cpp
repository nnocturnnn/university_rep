#include "Cooperator.h"

Cooperator::Cooperator() {
}

Cooperator::Cooperator(Person person, Grade grade, Date date) 
    : person(person), grade(grade), date(date) {
}

Cooperator::~Cooperator() {
}


Person Cooperator::getPerson() {
	return this->person;
}
void Cooperator::setPerson(Person person) {
	this->person = person;
}


Date Cooperator::getDate() {
	return this->date;
}
void Cooperator::setDate(Date date) {
	this->date = date;
}


Grade Cooperator::getGrade() {
	return this->grade;
}
void Cooperator::setGrade(Grade grade) {
	this->grade = grade;
}
