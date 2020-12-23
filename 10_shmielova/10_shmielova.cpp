// 10_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Simpson.h"
#include <cassert>

using namespace std;

extern double  a_sec = 1;
extern double  b_sec = 2;

double fun(double x)
{
	return 1 / sqrt( (a_sec * a_sec * sin(x)) + (b_sec * b_sec * cos(x)) );
}

int main()
{
	double eps = 0.000000001, PI = 3.14159265359;
	float a = 0, b = PI / 2; //lower and upper limits
	for (int i = 0; i < 10; i++)
	{
		double first = 1 / agm(a_sec, b_sec);
		double second = (2 / PI) * simpson(a, b, eps, fun);
		cout << first << '\t' << second << '\n';
		a_sec *= 2;
		b_sec *= 3;
	}
}
