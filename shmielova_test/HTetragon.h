#pragma once

#include "Point.h"
#include "Segment.h"

class HTetragon
{
protected:
	double    _height;
	double    _width;
	double    _angle;
	Point     _point;

public:
	HTetragon(const double h, const double w, const double a, const Point p) 
		: _height(h), _width(w), _point(p), _angle(a) {};
	HTetragon() {};

	virtual ~HTetragon() {};

	virtual double height() const = 0;
	virtual double width() const = 0;

	virtual Point& setA(const Point&) = 0;
	virtual Point& setB(const Point&) = 0;
	virtual Point& setC(const Point&) = 0;
	virtual Point& setD(const Point&) = 0;

	virtual const Point apexA() const = 0;
	virtual const Point apexB() const = 0;
	virtual const Point apexC() const = 0;
	virtual const Point apexD() const = 0;

	virtual const Segment side_ab() const = 0;
	virtual const Segment side_bc() const = 0;
	virtual const Segment side_cd() const = 0;
	virtual const Segment side_da() const = 0;

	virtual double area() const = 0;
};