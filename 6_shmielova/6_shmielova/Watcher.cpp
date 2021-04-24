#define _CRT_SECURE_NO_WARNINGS

#include "Watcher.h"
#include "Timer.h"
#include "Date.h"

#include <iomanip>    
#include <chrono>     
#include <iostream>
#include <thread>
#include <ctime>

void Watcher::watchChecker()
{
	time_t t;
	time(&t);

	struct tm* today = gmtime(&t);

	if (date().year() < today->tm_year + 1900 || date().month() - 1 > today->tm_mon || date().day() < today->tm_mday)
	{
		throw "Bad date.\n";

	}
	else if (tTime().hour() >= 24 || tTime().minute() < today->tm_min)
	{
		throw "Bad time.\n";
	}

}

Watcher::Watcher(Date& d, Time& t) : _date(d), _time(t) { watchChecker();  cout << "Watcher created!\n"; }

Watcher::Watcher(const Watcher& watcher) : _date(watcher._date), _time(watcher._time) { watchChecker(); cout << "Watcher created!\n"; }

Watcher::~Watcher() { cout << "Watcher deleted!\n"; return; };

Watcher& Watcher::operator=(const Watcher& watcher)
{
	_date = watcher._date;
	_time = watcher._time;

	return *this;
}

#pragma warning(disable : 4996)

bool Watcher::dateValid(tm* today)
{
	return today->tm_hour + 2 == tTime().hour() && today->tm_min == tTime().minute() && today->tm_sec == tTime().second();
}

bool Watcher::timeValid(tm* today)
{
	return date().day() == today->tm_mday && date().month() == today->tm_mon + 1 && (date().year() == today->tm_year + 1900);
}


void Watcher::begin()
{
	//auto* td = new tm;
	time_t t;
	time(&t);

	struct tm* today = gmtime(&t);

	cout << "waiting: " << date() << " : " << tTime() << '\n';

	while (dateValid(today) != true || timeValid(today) != true)
	{
		time(&t);
		today = gmtime(&t); 
		this_thread::sleep_for(chrono::seconds(1));

		cout << today->tm_mday << "/" << today->tm_mon + 1 << "/" << today->tm_year + 1900 << "\n" << today->tm_hour + 2 << ":"
			<< today->tm_min << ":" << today->tm_sec << "\n\n";
	}
}

ostream& operator<<(ostream& os, const Watcher& watcher)
{
	cout << "Watcher's parametres: " << watcher.tTime() << " on " << watcher.date() << '\n';
	return os;
}

