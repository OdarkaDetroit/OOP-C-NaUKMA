#include <iostream>
#include <cmath>

#include "Simpson.h"
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

float simpson(const float a, const float b, const double eps, double(* const pf)(double))
{
	double h = 0, sum = 0;
	int m = 2;
	int j = 0;
	h = (b - a) / m;

	double sum_1 = h * ( pf(a) + pf(b) );
	double sum_2 = 0;
	double sum_3 = 4 * h * pf(a + h);
	double res = sum_1 + sum_2 + sum_3;

	do {
		res = sum;
		m *= 2;
		h /= 2; 
		sum_1 *= 0.5; sum_2 = 0.5 * sum_2 + 0.25 * sum_3; 
		sum_3 = 0; 
		int i = 1;

		do 
		{
			sum_3 = sum_3 + pf(a + i * h); 
			i += 2;

		} while (i <= m);

		sum_3 = 4 * h * sum_3; 
		sum = sum_1 + sum_2 + sum_3;

	} while (fabs(sum - res) > eps);

	return sum / 3;
}

double rectangleMethod(const float a, const float b, const unsigned m, double(* const pf)(double fun))
{
	double step = (b - a) / m, sum = 0;
	for (int i = 0; i < m; i++)
		sum += pf(a + (i + 0.5) * step) * step;
	return sum;
}