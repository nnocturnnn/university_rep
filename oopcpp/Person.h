#pragma once
#include <iostream>

class Person
{
protected:
    std::string name;
    std::string surname;
    Date data;



public:
    Person(/* args */);
    Person(std::string name, std::string surname, Date data);
    std::string getName();
    void setName(std::string name);
    std::string getSurname();
    void setSurname(std::string surname);
    Date getData();
    void setData(Date data);
    ~Person();
};