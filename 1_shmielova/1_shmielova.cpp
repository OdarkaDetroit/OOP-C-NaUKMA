// 1_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Fun.h"

ostream& operator<<(ostream& os, const Point& poin)
{
	cout << "(" << poin.x() << ", " << poin.y() << ")";
	return os;
}

const Point operator+ (const Point& u, const Point& v)
{
	return Point(u.x() + v.x(), u.y() + v.y());
}

Point& Point::operator=(const Point& u)
{
	_x = u._x;
	_y = u._y;
	return *this;
}

Point& operator+=(Point& u, const Point& v)
{
	u.x() += v.x();
	u.y() += v.y();

	return u;
}

bool operator==(const Point& u, const Point& v)
{
	bool res = true;
	res = res && (v.x() == u.x()) && (v.y() == u.y());
	return res;
}

bool operator!=(const Point& u, const Point& v)
{
	return !(u == v);
}

//Point::Point(const double x, const double y) :
//	_x(x), _y(y), // Ініціалізація координат
//	 // Надання точці власного інвентарного номера
//	_pointID(++_freeID) {
//	cout << _pointID << ": created " << *this << endl;
//	return;
//}

Point::Point(double x, double y) : _x(x), _y(y), _pointID(++_freeID) { return; }

Point::Point(const Point& u) : _x(u._x), _y(u._y), _pointID(++_freeID) { return; }

Point::~Point() { return; }
