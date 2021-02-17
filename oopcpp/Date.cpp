#include "Date.h"

Date::Date() {
    day = month = year = 0;
}
Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::read_date(void) {
    char date1[11];
    cout << "Enter a date in the form of dd/mm/yy\n";
    cin.getline(date1, 11);
    unsigned length = strlen(date1);
    for (unsigned i = 0; i < length; ++i) {
        if (isalpha(date1[i])) {
            cerr << "Error: Alphabet character found: " << date1[i] << endl;
            return;
        }
        if ((ispunct(date1[i])) && (date1[i] != '/')) {
            cerr << "Illegal character: " << date1[i] << endl;
            return;
        }
    }
    convert_date(date1);
}

void Date::convert_date(char *date1){
    char *result;  
    result = strtok(date1, "/");
    day = strtol(result, nullptr, 10);
    result = strtok(nullptr, "/");
    month = strtol(result, nullptr, 10);
    result = strtok(nullptr, "/");
    year = strtol(result, nullptr, 10);

    if ((day <= 0) || (day >= 32)) {
        cerr << "Day is limited between 1 and 31, you entered: " << day << endl;
        day = month = year = 0;
        return;
    }
    if ((month <= 0) || (month >= 13)) {
        cerr << "Month is limited between 1 and 12, you entered: " << month << endl;
        day = month = year = 0;
        return;
    }
    if ((year <= 1899) || (year >= 2018)) {
        cerr << "year is limited between 1900 and 2017, you entered: " << year << endl;
        day = month = year = 0;
        return;
    }
}


int Date::get_day(void) {
    return day;
}
int Date::get_month(void) {
    return month;
}
int Date::get_year(void) {
    return year;
}
void Date::set_day(int day) {
    if ((day <= 0) || (day >= 32)) {
        cerr << "Day is limited between 1 and 31, you entered: " << day << endl;
        return;
    }
    this->day = day;
}
void Date::set_month(int month) {
    if ((month <= 0) || (month >= 13)) {
        cerr << "Month is limited between 1 and 12, you entered: " << month << endl;
        return;
    }
    this->month = month;
}
void Date::set_year(int year) {
    if ((year <= 1899) || (year >= 2018)) {
        cerr << "year is limited between 1900 and 2017, you entered: " << year << endl;
        return;
    }
    this->year = year;
}