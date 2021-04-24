#pragma once

#include "HParallelogram.h"

class HRomb : virtual public HParallelogram
{
public:
	// ???????????
	HRomb(const double side, const double a, const Point p) :
		HParallelogram(side, side, a, p) {}
	HRomb() {}
	// ???????????
	~HRomb() {}
};
