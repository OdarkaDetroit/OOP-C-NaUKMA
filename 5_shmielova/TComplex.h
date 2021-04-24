#pragma once

#include<cmath>
#include <iostream>

using namespace std;

class AComplex;
const double pi = 3.141592653589793238463;

class TComplex
{
private:
	static int freeID;
	int ID;
	double _r;
	double _phi;
public:
	TComplex(double r = 0, double phi = 0);
	TComplex(const TComplex&);
	~TComplex();

	operator AComplex() const;

	TComplex& operator=(const TComplex&);


	double& mod() { return _r; }
	double& arg() { return _phi; }

	const double& mod() const { return _r; }
	const double& arg() const { return _phi; }


	double re() const { return _r * cos(_phi * pi / 180); }
	double im() const { return _r * sin(_phi * pi / 180); }

	TComplex& operator+= (const TComplex&);
	TComplex& operator-= (const TComplex&);

	const int getID() const { return ID; }
};


const TComplex operator*(const TComplex&, const TComplex&);
const TComplex operator/(const TComplex&, const TComplex&);

//TComplex& operator+=(TComplex&, const TComplex&);
//TComplex& operator-=(TComplex&, const TComplex&);

TComplex& operator*=(TComplex&, const TComplex&);
TComplex& operator/=(TComplex&, const TComplex&);

ostream& operator<<(ostream&, const TComplex&);