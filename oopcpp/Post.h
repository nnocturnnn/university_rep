#pragma once
#include <iostream>
#include "Grade.h"

class Post {
private:
    int salary;
    std::string name;
    Grade grade;

public:
    Post(/* args */);
    Post(std::string name, int salary, Grade grade);
    ~Post();
    int getSalary();
    std::string getName();
    Grade getGrade();
    void setSalary(int salary);
    void setName(std::string name);
    void setGrade(Grade grade);

};
