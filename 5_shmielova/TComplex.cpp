#include "TComplex.h"
#include "AComplex.h"

#include<iostream>
#include <cstdlib>

using namespace std;


int TComplex::freeID = 0;

TComplex::TComplex(double r, double phi) :
	_r(r),
	_phi(phi),
	ID(++freeID)
{
#ifndef NDEBUG
	cout << "trig " << ID << ": " << *this << endl;
#endif // !NDEBUG
	return;
}

TComplex::TComplex(const TComplex& tc) :
	_r(tc.mod()),
	_phi(tc.arg()),
	ID(++freeID)
{
#ifndef NDEBUG
	cout << "trig " << ID << " is a copy of " << tc.getID() << ": " << *this << endl;
#endif // !NDEBUG
	return;
}

TComplex::~TComplex()
{
#ifndef NDEBUG
	cout << "trig " << getID() << " was deleted: " << *this << endl;
#endif // !NDEBUG
}



TComplex::operator AComplex() const
{
	return AComplex(re(), im());
}

TComplex& TComplex::operator=(const TComplex& tc)
{
	_r = tc._r;
	_phi = tc._phi;
	return *this;
}

const TComplex operator*(const TComplex& a, const TComplex& b)
{
	return TComplex(a.mod() * b.mod(), a.arg() + b.arg());
}

const TComplex operator/(const TComplex& a, const TComplex& b)
{
	return TComplex(a.mod() / b.mod(), a.arg() - b.arg());
}

TComplex& operator*=(TComplex& a, const TComplex& b)
{
	a.mod() *= b.mod();
	a.arg() += b.arg();
	return a;
}

TComplex& operator/=(TComplex& a, const TComplex& b)
{
	a.mod() /= b.mod();
	a.arg() -= b.arg();
	return a;
}

////////////////////////////////////////////////
//TComplex& operator+=(TComplex& a, const TComplex& b)
//{
//	a.mod() += b.mod();
//	a.arg() += b.arg();
//	return a;
//}
//
//TComplex& operator-=(TComplex& a, const TComplex& b)
//{
//	a.mod() -= b.mod();
//	a.arg() -= b.arg();
//	return a;
//}
////////////////////////////////////////////////

TComplex& TComplex::operator+= (const TComplex& a)
{
	TComplex _b(*this);
	TComplex _a(a);
	*this = (_b *= _a);
	return *this;
}
TComplex& TComplex::operator-= (const TComplex& a)
{
	TComplex _b(*this);
	TComplex _a(a);
	*this = (_b /= _a);
	return *this;
}


ostream& operator<<(ostream& os, const TComplex& t)
{
	os << t.mod() << '(' << cos(t.arg() * pi / 180) << " + i" << sin(t.arg() * pi / 180) << ')' << endl;
	return os;
}
