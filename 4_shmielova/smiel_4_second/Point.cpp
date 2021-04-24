#include "Header_p.h"

#include <iostream>
#include <cmath>

using namespace std;

int Point::_call = 0;
int Point::_freeID(0);

Point::Point(double x, double y) : _x(x), _y(y), myId(++_freeID)
{
	++_call;
#ifndef NDEBUG
	cout << myId << " Point created (copied) " << *this << '\n';
#endif
};

Point::Point(const Point& u) : _x(u._x), _y(u._y), myId(++_freeID)
{
	++_call;
#ifndef NDEBUG
	cout << myId << " Point created (copied) " << *this << '\n';
#endif
	return;
};

Point::~Point()
{
#ifndef NDEBUG
	cout << myId << " Point deleted " << *this << '\n';
#endif
};

Point& Point::operator=(const Point& p)
{
	++_call;
	_x = p._x;
	_y = p._y;
	return *this;
}

double& Point::x() { return _x; }

double& Point::y() { return _y; }

const double& Point::x()const { return _x; }

const double& Point::y()const { return _y; }

int Point::amount() { return _freeID; }

bool operator==(const Point& u, const Point& v)
{
	return (u.x() == v.x()) && (u.y() == v.y());
}

bool operator!=(const Point& u, const Point& v)
{
	return !(u == v);
}

const Point operator+ (const Point& u, const Point& v)
{
	return Point(u.x() + v.x(), u.y() + v.y());
}

Point& operator+=(Point& u, const Point& v)
{
	u.x() += v.x();
	u.y() += v.y();

	return u;
}

const Point operator- (const Point& u, const Point& v)
{
	return Point(u.x() - v.x(), u.y() - v.y());
}

ostream& operator<<(ostream& os, const Point& p)
{
	os << "( " << p.x() << ", " << p.y() << " )\n";
	return os;
}