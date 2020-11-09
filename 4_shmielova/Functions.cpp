#include "Functions.h"
#include <cmath>

using namespace std;

double agm(const double a, const double b)
{
	double aa = a;
	double bb = b;
	//у разі якщо а більше за b
	if (a > b) 
	{ 
		aa += bb;
		bb = aa - bb;
		aa -= bb;
	}
	
	{
		double aNext = sqrt(a * b);
		double bNext = (a + b) / 2.0;
		do 
		{
			aa = aNext;
			bb = bNext;

			aNext = sqrt(aa * bb);
			bNext = (aa + bb) / 2.0;

		} while (aa < aNext && aNext < bNext && bNext < bb);

		return aa;
	}
}