#pragma once
#include <iostream>
#include "Person.h"
#include "Grade.h"
#include "Date.h"

class Cooperator : public Person
{
private:
    Person person;
    Grade grade;
    Date date;


public:
    Cooperator(/* args */);
    Cooperator(Person person, Grade grade, Date date);
    ~Cooperator();
    void setPerson(Person person);
    Person getPerson();
    void setDate(Date date);
    Date getDate();
    void setGrade(Grade grade);
    Grade getGrade();
};


