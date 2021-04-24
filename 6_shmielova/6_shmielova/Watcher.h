#pragma once

#include "Time.h"
#include "Date.h"

class Watcher
{
private:
	Time& _time;
	Date& _date;

	void watchChecker();

public:
	Watcher(Date&, Time&);
	Watcher(const Watcher&);
	~Watcher();
	Watcher& operator=(const Watcher&);

	//geters 
	Time tTime() const { return _time; };
	Date date() const { return _date; };

	//seters
	Time& tTime() { return _time; };
	Date& date() { return _date; };

	//methods
	void begin();
	bool dateValid(tm* );
	bool timeValid(tm*);

};

ostream& operator<<(ostream& os, const Watcher& watcher);

