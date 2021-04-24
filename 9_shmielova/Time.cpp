#include "Time.h"

#include <iostream>
#include <chrono>;
#include <ctime> ;
using std::chrono::system_clock;

void Time::normalizeTime()
{
	_hour += ((_minute + (_second / 60)) / 60);
	_hour %= 24;
	_minute = (_minute == -1) ? 59 : ((_minute + (_second / 60)) % 60);
	_second = (_second == -1) ? 59 : (_second %= 60);
}


Time::Time(int h, int m, int s) : _hour(h), _minute(m), _second(s) 
{ 
	normalizeTime();
#ifndef NDEBUG
	cout << "Time created!\n";
#endif
};

Time::Time(const Time& time) : _hour(time._hour), _minute(time._minute), _second(time._second) 
{ 
	normalizeTime(); 
#ifndef NDEBUG
	cout << "Time created!\n";
#endif
};

Time::~Time() 
{ 
#ifndef NDEBUG
	cout << "Time deleted!\n";
#endif
	return;
}

Time& Time::operator=(const Time& time)
{
	_hour = time.hour();
	_minute = time.minute();
	_second = time.second();

	return *this;
}

const Time& Time::operator++()
{
	++_second;
	normalizeTime();
	return *this;
}

const Time Time::operator++(int i)
{
	Time res = *this;
	++* this;
	normalizeTime();
	return res;
}

const Time& Time::operator--()
{
	--_second;
	normalizeTime();
	return *this;
}

const Time Time::operator--(int i)
{
	Time res = *this;
	--* this;
	normalizeTime();
	return res;
}

#pragma warning(disable : 4996)

Time currentTime()
{
	time_t tt = system_clock::to_time_t(system_clock::now());
	struct tm* today = localtime(&tt);
	return Time(today->tm_hour, today->tm_min, today->tm_sec);
}

double operator+ (const Time& t1, const Time& t2)
{
	return double(t1) + double(t2);
}

ostream& operator<<(ostream& strm, const Time& time)
{
	return strm << time.hour() << ':' << time.minute() << ':' << time.second();
}

