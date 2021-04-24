#pragma once

#include <iostream>

using namespace std;

class Point
{

private:
	double _x;
	double _y;

public:
	// ????????????
	Point(double x = 0, double y = 0);
	Point(const Point&);
	// ??????????
	~Point();

	// ???????
	double& x();
	double& y();
	// ??????
	const double& x()const;
	const double& y()const;

	Point& operator=(const Point&);
};

ostream& operator<<(ostream&, const Point&);

const Point operator+ (const Point& u, const Point& v);
const Point operator- (const Point& u, const Point& v);

Point& operator+=(Point&, const Point&);

bool operator==(const Point& u, const Point& v);
bool operator!=(const Point& u, const Point& v);

