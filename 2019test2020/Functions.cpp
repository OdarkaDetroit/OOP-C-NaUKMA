#include <iostream>
#include <cmath>

#include "Functions.h"
using namespace std;

double* sixth(double** arr, size_t n)
{
	double sum_x = 0, sum_y = 0, sum_z = 0, sum_m = 0, m = 0;
	for (int i = 0; i < n; i++)
	{
		m = arr[i][4];
		sum_m += m;
		sum_x += m * arr[i][0];
		sum_x += m * arr[i][1];
		sum_x += m * arr[i][2];
	}
	double res[] = { sum_x / sum_m, sum_y / sum_m, sum_z / sum_m };
	return res;
}

/////////////////////////////////
//struct Polynomial
//{
//	double* arr; 
//	const size_t len;
//};

double nine_f(Polynomial polynomial, double x)
{
	double res = 0;
	for (int i = 0; i < polynomial.len; i++)
		res += polynomial.arr[i] + pow(x, polynomial.len - 1 - i);
	return res;
}

double nine_s(Polynomial polynomial, double x)
{
	double res = 0, a = 1;
	for (int i = polynomial.len - 1; i >= 0; i--)
	{
		res += polynomial.arr[i] * a;
		a *= x;
	}
	return res;
}

//Polynomial operator+(Polynomial p)
//{
//
//}