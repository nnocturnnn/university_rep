#pragma once
#include "Cooperator.h"
#include <list>

class Department
{
private:
    std::string name;
    std::string TopManager;
    list <Cooperator> Cooperators;

public:
    Department(/* args */);
    Department(std::string name, std::string TopManager, list <Cooperator> Cooperators);
    ~Department();
    std::string getName();
    std::string getTopManager();
    void setName(std::string name);
    void setTopManager(std::string TopManager);
    list<Cooperator> getCooperator();
    void setCooperator(list <Cooperator> Cooperators);
};

