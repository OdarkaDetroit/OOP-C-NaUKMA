#include "Header_s.h"
#include "Header_t.h"

#include <iostream>

using namespace std;

int Triangle::count = 0;

Triangle::Triangle(const double x1, const double y1,
	const double x2, const double y2,
	const double x3, const double y3) :
	_a(x1, y1), _b(x2, y2), _c(x3, y3)
{
	count++;
#ifndef NDEBUG
	cout << " Triangle created " << *this << " !\n";
#endif
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : _a(a), _b(b), _c(c)
{
	count++;
#ifndef NDEBUG
	cout << " Triangle created " << *this << " !\n";
#endif
}

Triangle::Triangle(const Triangle & t) : _a(t.apexA()), _b(t.apexB()), _c(t.apexC())
{
	count++;
#ifndef NDEBUG
		cout << " Triangle created " << *this << " !\n";
#endif
}

	Triangle::~Triangle() {}

	Triangle& Triangle::operator=(const Triangle & t)
	{
		_a = t.apexA();
		_b = t.apexB();
		_c = t.apexC();
		return *this;
	}

	const Triangle::Segment& Triangle::side_a() const
	{
		if (_bc == 0)
			_bc = new Triangle::Segment(_b, _c);
		return *_bc;
	}
	const Triangle::Segment& Triangle::side_b() const
	{
		if (_ca == 0)
			_ca = new Triangle::Segment(_c, _a);
		return *_ca;
	}
	const Triangle::Segment& Triangle::side_c() const
	{
		if (_ab == 0)
			_ab = new Triangle::Segment(_a, _b);
		return *_ab;
	}

	Triangle::Segment& Triangle::side_a()
	{
		if (_bc == 0)
			_bc = new Triangle::Segment(_b, _c);
		return *_bc;
	}

	Triangle::Segment& Triangle::side_b()
	{
		if (_ca == 0)
			_ca = new Triangle::Segment(_c, _a);
		return *_ca;
	}

	Triangle::Segment& Triangle::side_c()
	{
		if (_ab == 0) _ab = new Triangle::Segment(_a, _b);
		return *_ab;
	}


	double Triangle::perimeter() const
	{
		return side_a().length() + side_b().length() + side_c().length();
	}
	double Triangle::area() const
	{
		return 0.5 * side_a().length() * side_a().distance(_a);
	}

	ostream& Triangle::show(ostream & os) const
	{
		os << "Triangle: " << apexA() << apexB() << apexC() << '\n';

		os << side_a();
		os << side_b();
		os << side_c();

		os << "P = " << perimeter() << '\n';
		os << "S = " << area() << '\n';

		return os;
	}

	double Triangle::length_a() const
	{
		return side_a().length();
	}

	double Triangle::length_b() const
	{
		return side_b().length();
	}

	double Triangle::length_c() const
	{
		return side_c().length();
	}

	int Triangle::amounte()
	{
		return count;
	}

	ostream& operator<<(ostream & os, const Triangle & t)
	{
		return t.show(os);
	}


	double dotTransform(const double x1, const double y1, const double x2, const double y2)
	{
		return x1 * x2 + y1 * y2;
	}

	const Point& projection(Triangle::Segment* const s, const Point& p)
	{
		const double t = dotTransform(p.x() - s->start().x(),
									  p.y() - s->start().y(),
								      s->end().x() - s->start().x(),
			                          s->end().y() - s->start().y()) / pow(s->length(),
				                        2);
		return *(new Point(s->start().x() + t * (s->end().x() - s->start().x()),
												 s->start().y() + t
													* (s->end().y() - s->start().y())));
	}

	const Triangle::Segment& Triangle::height_a() const
	{
		return *(new Triangle::Segment(_a, projection(_bc, _a)));
	}

	const Triangle::Segment& Triangle::height_b() const
	{
		return *(new Triangle::Segment(_a, projection(_ca, _b)));
	}

	const Triangle::Segment& Triangle::height_c() const
	{
		return *(new Triangle::Segment(_a, projection(_ab, _c)));
	}