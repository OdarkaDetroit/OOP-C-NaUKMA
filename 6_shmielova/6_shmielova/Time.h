#pragma once


#include <string>
#include <iostream>

using namespace std;

const double hourToDec = 1. / 3600.;

class Time

{

private:

	int _hour;
	int _minute;
	int _second;

	void normalizeTime();

public:

	Time(int h = 0, int m = 0, int s = 0);

	//Time(int h, int m, int s);

	Time(const Time& time);

	~Time();

	Time& operator=(const Time&);

	operator int() const { return _hour * 3600 + _minute * 60 + _second; }
	operator double() const { return int(*this) * hourToDec; }

	int hour() const { return _hour; }
	int minute() const { return _minute; }
	int second() const { return _second; }

	int& hour() { return _hour; }
	int& minute() { return _minute; }
	int& second() { return _second; }

	const Time& operator++();

	const Time operator++(int i);

	const Time& operator--();

	const Time operator--(int i);

};

Time currentTime();

double operator+ (const Time&, const Time&);

ostream& operator<<(ostream&, const Time&);