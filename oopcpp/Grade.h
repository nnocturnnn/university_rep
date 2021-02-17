#pragma once 

enum VC {
    Secretary, 
    Engineer,
    Manager, 
    Marketer, 
    Economist, 
    Planner, 
    Leader
};

class Grade {
    private:
        VC value;

    public:
        Grade();
        Grade(const VC& v) : value{v} {}
        operator VC() const { return value; }
        Grade::operator std::string() const {
        switch (value) {
            case Secretary: return "Secretary";
            case Engineer:  return "Engineer";
            case Manager:  return "Manager";
            case Marketer: return "Marketer";
            case Economist: return "Economist";
            case Planner: return "Planner";
            case Leader: return "Leader";
            }
        }
        Grade& operator=(VC v) { value = v; return *this;}
};