#include <cmath>
#include "Functions.h"
#include <cassert>
#include <iostream>
using namespace std;

double dichotomy(double (*fun)(double), double a, double b, double eps)
{
	double left = a;
	double right = b;

	if (fun(a) * fun(b) >= 0)
	{
		return 0;
	}

	double c = a;
	if ((fun(a) < 0 && fun(b) > 0) || (fun(a) > 0 && fun(b) < 0))
	{
		while ((right - left) > eps)
		{
			// Find middle point 
			c = (left + right) / 2;

			// Check if middle point is root 
			if (fun(c) == 0.0)
			{
				return 0;
				break;
			}
			// Decide the side to repeat the steps 
			else if (fun(c) * fun(left) < 0)
				right = c;
			else
				left = c;
		}
		return left;
	}
}