#include "Department.h"



Department::Department(std::string name, std::string TopManager, list <Cooperator> Cooperators) 
: name(name), TopManager(TopManager), Cooperators(Cooperators) {
}

Department::~Department()
{
}



std::string Department::getName() {
	return this->name;
}
void Department::setName(std::string name) {
	this->name = name;
}


list<Cooperator> Department::getCooperator() {
	return this->Cooperators;
}
void Department::setCooperator(list <Cooperator> Cooperators) {
	this->Cooperators = Cooperators;
}


std::string Department::getTopManager() {
	return this->TopManager;
}
void Department::setTopManager(std::string TopManager) {
	this->TopManager = TopManager;
}
