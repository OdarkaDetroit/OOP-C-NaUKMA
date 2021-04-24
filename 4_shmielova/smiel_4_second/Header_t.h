#pragma once

#include "Header_s.h"
#include "Header_p.h"

#include <iostream>


class Triangle
{

public:

	class Segment
	{
	private:
		const Point& _a;

		const Point& _b;

		static int _freeID;
		int _myId;

		Segment(const Segment&);

		Segment& operator=(const Segment&);

	public:

		Segment(const Point& start, const Point& end);

		~Segment();

		const Point& start() const { return _a; };
		const Point& end() const { return _b; };

		double length() const;

		double distance(const Point&) const;

		int getID() const { return _myId; };
	};

	typedef Segment* Triangle::* SidePtr;

	Triangle(const double x1 = 0, const double y1 = 0, const double x2 = 1, const double y2 = 0, const double x3 = 0, const double y3 = 1);
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Triangle&);
	~Triangle();

	Triangle& operator=(const Triangle&);

	const Point& apexA() const { return _a; }
	const Point& apexB() const { return _b; }
	const Point& apexC() const { return _c; }

	const Segment& side_a() const;
	const Segment& side_b() const;
	const Segment& side_c() const;

	const Segment& height_a() const;
	const Segment& height_b() const;
	const Segment& height_c() const;

	Segment& side_a();
	Segment& side_b();
	Segment& side_c();

	double length_a() const;
	double length_b() const;
	double length_c() const;

	double perimeter() const;
	double area() const;

	std::ostream& show(std::ostream& os) const;

	static int amounte();

private:

	static int count;
	Point _a, _b, _c;
	mutable Segment* _ab = 0, * _bc = 0, * _ca = 0;
};

ostream& operator<<(ostream&, const Triangle&);

ostream& operator<<(ostream&, const Triangle::Segment&);
