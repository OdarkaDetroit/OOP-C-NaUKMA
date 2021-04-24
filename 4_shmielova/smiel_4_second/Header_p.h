#pragma once

#ifndef _HEADER_P_
#define _HEADER_P_

#include <iostream>

using namespace std;

class Point
{

private:

	int myId;
	static int _freeID;
	static int _call;
	double _x;
	double _y;

public:

	Point(double x = 0, double y = 0);
	Point(const Point&);
	~Point();
	Point& operator=(const Point&);
	double& x();
	double& y();
	const double& x()const;
	const double& y()const;
	int amount();

};

ostream& operator<<(ostream&, const Point&);

const Point operator+ (const Point& u, const Point& v);
const Point operator- (const Point& u, const Point& v);

Point& operator+=(Point&, const Point&);

bool operator==(const Point& u, const Point& v);
bool operator!=(const Point& u, const Point& v);


#endif