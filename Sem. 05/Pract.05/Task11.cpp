#include <iostream>
using namespace std;

bool isLeapYear(unsigned year) {
    
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    else
        return false;

}

unsigned daysInMonth(unsigned month, unsigned year) {
    unsigned days = 0;
    
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        days = 31;
    }
    else if (month == 2) {
        if (isLeapYear(year))
            days = 29;
        else
            days = 28;
    }
    else
        days = 30;

    return days;
}

bool isDateCorrect(unsigned days, unsigned months, unsigned year) {
    if (months > 12)
        return false;
    if (days > daysInMonth(months, year))
        return false;

    return true;
}

void dateAfterOneDay(unsigned& days, unsigned& month, unsigned& year) {
    days++;
    if (days > daysInMonth(month, year)) {
        days = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void dateAfterNDays(unsigned& days, unsigned& month, unsigned& year, unsigned n) {
    for (int i = 1; i <= n; i++) {
        dateAfterOneDay(days, month, year);
    }

}

int main()
{
    unsigned days; unsigned month; unsigned year;
    cin >> days >> month >> year;

    unsigned n;
    cin >> n;
    if (isDateCorrect(days, month, year)) {
        dateAfterNDays(days, month, year, n);
        cout << days << "." << month << "." << year << endl;
    }
    else
        cout << "Date is incorrect";
    
}

