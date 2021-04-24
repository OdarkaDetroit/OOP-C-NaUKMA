#include "Header_s.h"

#include <iostream>

using namespace std;

int Triangle::Segment::_freeID = 0;
unsigned int Segment::_freeID = 0;

Segment& Segment::operator=(const Segment& s) { return *this; }

Triangle::Segment::Segment(const Point& u, const Point& v) : _a(u), _b(v), _myId(++_freeID)
{
#ifndef NDEBUG
	cout << _myId << " Segment created " << *this << '\n';
#endif
	return;
}

Segment::~Segment()
{
#ifndef NDEBUG
	cout << _myId << " Segment deleted " << *this << endl;
#endif
}

double Triangle::Segment::length() const
{
	return sqrt(pow((_a.x() - _b.x()), 2) + pow((_a.y() - _b.y()), 2));
}

double Triangle::Segment::distance(const Point& c) const
{
	double A = (_a.x() == _b.x() ? 0 : 1 / (_b.x() - _a.x()));
	double B = (_b.y() == _a.y() ? 0 : 1 / (_a.y() - _b.y()));
	double C = -_a.x() * A - _a.y() * B;

	if (B == 0)
		return fabs(-C / A - c.y());
	if (A == 0)
		return fabs(-C / B - c.x());

	return fabs((A * c.x() + B * c.y() + C) / sqrt(pow(A, 2) + pow(B, 2)));
}

int Segment::amount() { return _freeID; }

std::ostream& operator<<(std::ostream& os, const Triangle::Segment& u)
{
	os << "Segment with ID " << u.getID() << " --> [ " << u.start() << ", " << u.end() << " ]\n";
	return os;
}
