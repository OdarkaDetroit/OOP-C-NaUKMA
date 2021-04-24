#include "TComplex.h"
#include "AComplex.h"

#include<iostream>
#include <cstdlib>

using namespace std;

int AComplex::freeID = 0;

AComplex::AComplex(double re, double im) :
	_re(re),
	_im(im),
	ID(++freeID)
{
#ifndef NDEBUG
	cout << "alg " << ID << ": " << *this << endl;
#endif // !NDEBUG
	return;
}

AComplex::AComplex(const AComplex& ac) :
	_re(ac.re()),
	_im(ac.im()),
	ID(++freeID)
{
#ifndef NDEBUG
	cout << "alg " << ID << " is a copy of " << ac.getID() << ": " << *this << endl;
#endif // !NDEBUG
	return;
}

AComplex::~AComplex()
{
#ifndef NDEBUG
	cout << "alg " << getID() << " was deleted: " << *this << endl;
#endif // !NDEBUG
}

AComplex::operator TComplex() const
{
	return TComplex(mod(), arg());
}

AComplex& AComplex::operator=(const AComplex& ac)
{
	_re = ac._re;
	_im = ac._im;
	return *this;
}



const AComplex operator+(const AComplex& u, const AComplex& v)
{
	return AComplex(u.re() + v.re(), u.im() + v.im());
}

const AComplex operator-(const AComplex& u, const AComplex& v)
{
	return AComplex(u.re() - v.re(), u.im() - v.im());
}

AComplex& operator+=(AComplex& a, const AComplex& b)
{
	a.re() += b.re();
	a.im() += b.im();
	return a;
}

AComplex& operator-=(AComplex& a, const AComplex& b)
{
	a.re() -= b.re();
	a.im() -= b.im();
	return a;
}

//////////////////////////////////////////////////

//AComplex& operator*=(AComplex& a, const AComplex& b)
//{
//	a.mod() *= b.mod();
//	a.arg() += b.arg();
//	return a;
//}
//
//AComplex& operator/=(AComplex& a, const AComplex& b)
//{
//	a.mod() /= b.mod();
//	a.arg() -= b.arg();
//	return a;
//}

//////////////////////////////////////////////////


AComplex& AComplex::operator*= (const AComplex& a)
{
	TComplex _b(*this);
	TComplex _a(a);
	*this = (_b *= _a);
	return *this;
}
AComplex& AComplex::operator/= (const AComplex& a)
{
	TComplex _b(*this);
	TComplex _a(a);
	*this = (_b /= _a);
	return *this;
}



bool operator==(const AComplex& a, const AComplex& b)
{
	return (a.re() == b.re() && a.im() == b.im());
}

bool operator!=(const AComplex& a, const AComplex& b)
{
	return !(a == b);
}


ostream& operator<<(ostream& os, const AComplex& a)
{
	os << '(' << a.re() << ", " << a.im() << "i)" << endl;
	return os;
}
