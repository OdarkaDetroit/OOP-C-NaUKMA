#pragma once

#include "Point.h"
#include "Segment.h"
#include "HParallelogram.h"
//#include "HTetragon.h"

const double pi = 3.141592653589793;

class HRectangle : virtual public HParallelogram
{
public:
	// конструктори
	HRectangle(const double h, const double w, const Point p) :
		HParallelogram(h, w, (pi/2), p),
		HTetragon(h, w, (pi/2), p) 
	{

	} 

	HRectangle() {}

	//деструктор
	~HRectangle() 
	{

	}  

	double height() const override  { return _height; }  //знаходження висоти прямокутника
	double width() const  override  { return _width; }   //знаходження ширини прямокутника

	// сетери вершин
	Point& setA(const Point& a) override { return _point = a; }
	Point& setB(const Point& b) override;
	Point& setC(const Point& c) override;
	Point& setD(const Point& d) override;

	//гетери для вершин
	const Point apexA() const override { return _point; }
	const Point apexB() const override { return Point(_point.x(), _point.y() + height()); }
	const Point apexC() const override { return Point(_point.x() + width(), _point.y() + height()); }
	const Point apexD() const override { return Point(_point.x() + width(), _point.y()); }

	//гетери сторін прямокутника
	virtual const Segment side_ab() const override { return Segment(apexA(), apexB()); }
	virtual const Segment side_bc() const override { return Segment(apexB(), apexC()); }
	virtual const Segment side_cd() const override { return Segment(apexC(), apexD()); }
	virtual const Segment side_da() const override { return Segment(apexD(), apexA()); }

	virtual double area() const override { return _height * _width; } //площа прямокутника

	HRectangle operator+(const HRectangle&);

	HRectangle& operator=(const HRectangle&);

	bool operator<(const HRectangle& r);

};

ostream& operator<<(ostream& os, const HRectangle& rectangle);
