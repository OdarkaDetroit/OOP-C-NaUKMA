#pragma once

#include <iostream>

#include "Header_t.h"
#include "Header_p.h"

using namespace std;

class Segment 
{

private:

	const Point& _a;
	const Point& _b;
	unsigned int _myId;
	static unsigned int _freeID;
	Segment(const Segment&);
	Segment& operator=(const Segment&);

public:

	Segment(const Point& u, const Point& v);
	~Segment();
	const Point& start()  const { return _a; };
	const Point& end() const const { return _b; };
	const int getID() const { return _myId; };
	double length() const;
	double distance(const Point&) const;
	static int amount();

};

ostream& operator<<(ostream&, const Triangle::Segment&);