#pragma once

#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

class Date {
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int day, int month, int year);

        void read_date(void);
        void convert_date(char *date1);
        int get_day(void);
        int get_month(void);
        int get_year(void);
        void set_day(int day);
        void set_month(int month);
        void set_year(int year);
};