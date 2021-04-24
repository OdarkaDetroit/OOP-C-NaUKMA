#include <iostream>
#include <cmath>
#include "Fun.h"


Segment::Segment(const double x1, const double y1,
	const double x2, const double y2) : 
	_a(x1, y1), _b(x2, y2), _myId(++_freeID) 
    { return; }

Segment::Segment(const Point& start, const Point& end) : _a(start), _b(end), _myId(++_freeID) { return; }

Segment::Segment(const Segment& seg) : _a(seg._a), _b(seg._b), _myId(++_freeID) { return; }

Segment::~Segment() // Деструктор
{ 
    cout << "delete\n";
    return; 
}             

Segment& Segment::operator=(const Segment& seg)
{
	_a = seg._a;
	_b = seg._b;
	return *this;
}

// Селектори  точок

const Point& Segment::start() const { return _a; }

const Point& Segment::end() const { return _b; }

// Селектори-модифікатори точок

Point& Segment::start() { return _a; }

Point& Segment::end() { return _b; }

// Селектори координат точок

const double& Segment::startX() const { return _a.x(); }

const double& Segment::startY() const { return _a.y(); }

const double& Segment::endX() const { return _b.x(); }

const double& Segment::endY() const { return _b.y(); }

// Селектори-модифікатори координат точок

double& Segment::startX() { return _a.x(); }

double& Segment::startY() { return _a.y(); }

double& Segment::endX() { return _b.x(); }

double& Segment::endY() { return _b.y(); }

// Обчислення довжини відрізка

double Segment::length() const
{
	//double len = pow((_a.x - _b.x)
	double len = sqrt(pow((startX() - endX()), 2) + pow((startY() - endY()), 2));
	return len;
}

// Обчислення відстані від відрізка до точки

double Segment::distance(Point& poin) const
{
	double dist =  
		           abs( 
					    ( endY() - startY() ) * poin.x()
					     
		                - 
					     
						 ( endX() - startX() ) * poin.y()
					    
		                 +  startY() * endX()  
		                 -  startX() * endY()  
				      )       
		;
	return dist / length();
}

// Селектор ID

const int Segment::getID() const { return _myId; }

ostream& operator<<(ostream& os, const Segment& seg)
{
	cout << "the start coordinates = ( " << seg.startX() << ", " << seg.startY() 
		 << " )\nthe end coordinates = ( " << seg.endX() << ", " << seg.endY()
		 << " )\n\n";
	return os;
}

const Point operator+ (const Point& u, const Point& v)
{
	return Point(u.x() + v.x(), u.y() + v.y());
}

//Point& Point::operator=(const Point& u)
//{
//	_x = u._x;
//	_y = u._y;
//	return *this;
//}

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

const Point operator* (const Point& u, const Point& v)
{
	return Point(u.x() * v.x(), u.y() * v.y());
}