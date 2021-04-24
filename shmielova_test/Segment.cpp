#include "Segment.h"

Segment::Segment(const Point& a, const Point& b) : _a(a), _b(b) 
{
	return;
}

Segment::Segment(const Segment& u) : _a(u._a), _b(u._b) 
{
}

Segment::~Segment() 
{
}

double Segment::length() const 
{
	return sqrt(pow((_b.x() - _a.x()), 2) + pow((_b.y() - _a.y()), 2));
}

/////////////////////////////////////////////////// ???????? ?????????

ostream& operator<<(ostream& os, const Segment& u)
{
	os << "Segment --> [ " << u.start() << ", " << u.end() << " ]\n";
	return os;
}