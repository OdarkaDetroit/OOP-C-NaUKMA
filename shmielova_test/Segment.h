#pragma once

#include "Point.h"

class Segment
{
private:
	const Point _a;
	const Point _b;

public:
	Segment(const Point&, const Point&);
	Segment(const Segment&);
	~Segment() ;

	const Point& start() const { return _a; }
	const Point& end() const { return _b; }

	const double& startX() const { return _a.x(); }
	const double& startY() const { return _a.y(); }
	const double& endX() const { return _b.x(); }
	const double& endY() const { return _b.y(); }

	double length() const;
};
ostream& operator<<(ostream&, const Segment&);