#include "Person.h"
#include "Date.h"

Person::Person(std::string name, std::string surname, Date date) : 
    name(name), surname(surname), data(date) {
}

Person::~Person() {
}

Date Person::getData() {
	return this->data;
}
void Person::setData(Date data) {
	this->data = data;
}

std::string Person::getSurname() {
	return this->surname;
}
void Person::setSurname(std::string surname) {
	this->surname = surname;
}

std::string Person::getName() {
	return this->name;
}
void Person::setName(std::string name) {
	this->name = name;
}
