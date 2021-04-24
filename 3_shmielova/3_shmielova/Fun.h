#pragma once

#include <string>
#include <iostream>

using namespace std;


class Date

{

public:


	enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

	struct BadDate;   // to avoid problem 7.2.2002 7 feb or jul 2?

	Date(int d = 0, Month m = Month(0), int y = 0);

	Date(int d, int m, int y);

	Date(const Date& dat);

	~Date();

	int day() const;

	Month month() const;

	int year() const;

	const string getMonthName() const;

	void setDay(int d);

	void setMonth(int m);

	void setYear(int y);

	void setDefault(int d, Month m, int y);

	void setDefault();

	void showDefault();

	const Date& operator++();

	const Date  operator++(int);

	const Date& operator--();

	const Date  operator--(int);

private:

	int _day, _month, _year;

	bool leapYear(int y);

	void fillDate(int d, Month m, int y);

	static string monthNames[12];

	static bool defaultSet;

	static Date defaultDate;

};

ostream& operator<<(ostream& os, const Date& d);
ostream& operator<<(ostream& os, const Date::BadDate& bd);

struct Date::BadDate
{
	int _day, _month, _year;
	BadDate(int d, int m, int y) :_day(d), _month(m), _year(y)
	{
		cout << "BadDate issue => " << _day << "/ " << _month << "/ " << _year << '\n';
	};
};

