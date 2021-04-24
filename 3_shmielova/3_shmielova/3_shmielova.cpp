// 3_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>

#include "Fun.h"

string Date::monthNames[12] = 
{
 "Jan", "Feb", "Mar", "Apr", "May", "Jun",
 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};


ostream& operator<<(ostream& os, const Date::BadDate& bd)
{
    os << "BadDate: " << bd._day << "/ " << bd._month << "/ " << bd._year << '\n';
    return os;
}

ostream& operator<<(ostream& os, const Date& d)
{
    os << "Date: " << d.day() << "/ " << d.getMonthName() << "/ " << d.year() << '\n';
    return os;
}


Date::Date(int d, Month m, int y) { fillDate(d, m, y); return; }

Date::Date(int d, int m, int y){ fillDate(d, Month(m), y); return; }

Date::Date(const Date& dat) { fillDate(dat._day, Month(dat._month), dat._year); }

Date::~Date() { cout << "Deleted!\n";  return; }

int Date::day() const { return _day; }

Date::Month Date::month() const { return Month(_month); }

int Date::year() const { return _year; }

const string Date::getMonthName() const { return monthNames[_month - 1]; }

Date Date::defaultDate;

bool Date::leapYear(int y)
{

    return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0) ? true : false;
}

void Date::fillDate(int d, Month m, int y) 
{
    if (!defaultSet)
        setDefault(); // програми

#ifndef NDEBUG
    cout << "Data constructor _defaultDate: " << defaultDate << '\n';
#endif
    // Тепер аналізуємо параметри: ті, яких немає (вони нульові), беремо
    // із заданої за умовчанням дати, яку вже гарантовано визначено

    int months[12]{ 31, (28 + leapYear(y)), 31, 30, 31, 31, 30, 31, 30, 31, 30, 31 };



    _day = d ? d : defaultDate._day;
    _month = m ? m : defaultDate._month;
    _year = y ? y : defaultDate._year;
    
    cout << *this << '\n';

    if (_day > months[_month - 1] || _day <= 0 || _month > 12)
    {
        throw BadDate(_day, _month, _year);
    }
}

void Date::setDay(int d)
{
      fillDate(d, Month(_month), _year);
    //_day = d;
}

void Date::setMonth(int m)
{
    fillDate(_day, Month(m), _year);
    //_month = m;
}

void Date::setYear(int y)
{
    fillDate(_day, Month(_month), y);
    //_year = y;
}


void Date::setDefault(int d, Date::Month(m), int y)
{
    defaultDate = Date(d, m, y);
    //defaultSet = true;
}

void Date::setDefault()
{
    time_t timer; 
    time(&timer);
    tm* today = new tm;
    gmtime_s(today, &timer);

    defaultDate._day = today -> tm_mday;
    defaultDate._month = ++(today -> tm_mon);
    defaultDate._year = today -> tm_year += 1900;
}

void Date::showDefault()
{
    cout << defaultDate;
}

const Date& Date::operator++()
{
    int months[12]{ 31, (28 + leapYear(_year)), 31, 30, 31, 31, 30, 31, 30, 31, 30, 31 };
    if (_day == months[_month - 1])
    {
        if (_month == 12) 
        {
            fillDate(1, Month(1), ++_year);
        }
        else 
        {
            _month++;
            _day = 1;
        }
    }
    else 
    {
        fillDate(_day + 1, Month(_month), _year);
    }
    return *this;
}

const Date Date::operator++(int)
{
    Date copy(*this);
    int months[12]{ 31, (28 + leapYear(_year)), 31, 30, 31, 31, 30, 31, 30, 31, 30, 31 };
    if (_day == months[_month - 1])
    {
        if (_month == 12)
        {
            this -> fillDate(1, Month(1), ++_year);
        }
        else
        {
            this -> _month++;
            this -> _day = 1;
        }
    }
    else
    {
        fillDate(_day + 1, Month(_month), _year);
    }
    return copy;
}

const Date& Date::operator--()
{
    int months[12]{ 31, (28 + leapYear(_year)), 31, 30, 31, 31, 30, 31, 30, 31, 30, 31 };
    if (_day == months[_month - 1])
    {
        if (_month == 12)
        {
            fillDate(1, Month(1), --_year);
        }
        else
        {
            _day = months[_month - 1];
            _month--;
        }
    }
    else
    {
        fillDate(_day - 1, Month(_month), _year);
    }
    return *this;
}

const Date Date::operator--(int)
{
    Date copy(*this);
    int months[12]{ 31, (28 + leapYear(_year)), 31, 30, 31, 31, 30, 31, 30, 31, 30, 31 };
    if (_day == 1) {
        if (_month == 1) {
            fillDate(31, Month(12), --_year);
        }
        else {
            _day = months[_month - 1];
            _month--;
        }
    }
    else {
        fillDate(_day - 1, Month(_month), _year);
    }
    return copy;
}