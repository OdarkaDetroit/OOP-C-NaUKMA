#pragma once
#pragma once

#include <iostream>
#include <cmath>

using namespace std;
const double PI = 3.141592653589793238463;
class TComplex;

class AComplex
{
private:
	static int freeID;
	int ID;
	double _re;
	double _im;

public:
	AComplex(double re = 0, double im = 0);
	AComplex(const AComplex&);
	~AComplex();

	operator TComplex() const;

	AComplex& operator=(const AComplex&);

	double& re() { return _re; }
	double& im() { return _im; }

	const double& re() const { return _re; }
	const double& im() const { return _im; }



	double mod() const { return sqrt(_re * _re + _im * _im); }
	double arg() const { return atan2(_im, _re) * 180 / PI; }

	const AComplex conj() const
	{
		return AComplex(_re, -_im);
	}

	const int getID() const { return ID; }

	AComplex& operator*= (const AComplex&);
	AComplex& operator/= (const AComplex&);
};

const AComplex operator+(const AComplex& u, const AComplex& v);
const AComplex operator-(const AComplex& u, const AComplex& v);

//AComplex& operator*=(AComplex&, const AComplex&);
//AComplex& operator/=(AComplex&, const AComplex&);

AComplex& operator+=(AComplex&, const AComplex&);
AComplex& operator-=(AComplex&, const AComplex&);

bool operator==(const AComplex&, const AComplex&);
bool operator!=(const AComplex&, const AComplex&);



ostream& operator<<(ostream&, const AComplex&);