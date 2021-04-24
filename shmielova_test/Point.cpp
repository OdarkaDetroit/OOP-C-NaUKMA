#include "Point.h"

#include <iostream>
#include <cmath>

using namespace std;


Point::Point(double x, double y) : _x(x), _y(y)
{
};

Point::Point(const Point& u) : _x(u._x), _y(u._y)
{
	return;
};

Point::~Point()
{

};

double& Point::x() { return _x; }

double& Point::y() { return _y; }

const double& Point::x()const { return _x; }

const double& Point::y()const { return _y; }

////////////////////////////// ==, !=, +, +=, -, =

Point& Point::operator=(const Point& p)
{
	_x = p._x;
	_y = p._y;
	return *this;
}

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

const Point operator-(const Point& u, const Point& v)
{
	return Point(u.x() - v.x(), u.y() - v.y());
}

////////////////////////////// оператор виведення

ostream& operator<<(ostream& os, const Point& p)
{
	os << "( " << p.x() << ", " << p.y() << " )";
	return os;
}
