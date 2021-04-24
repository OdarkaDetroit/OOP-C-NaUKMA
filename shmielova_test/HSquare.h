#pragma once

#include "HRectangle.h"
#include "HRomb.h"



class HSquare: public HRectangle, public HRomb
{
public:
	// конструтори
	HSquare(const double height, const Point point) :
		HRectangle(height, height, point),
		HParallelogram(height, height, (pi / 2), point),
		HRomb(height, (pi / 2), point),
	    HTetragon(height, height, (pi / 2), point) {}

	HSquare(HRectangle& r);

	HSquare() {}
	//деструктуор
	~HSquare() override {}  

	HSquare operator+(const HSquare& r);

};

ostream& operator<<(ostream& os, const HSquare& t);

