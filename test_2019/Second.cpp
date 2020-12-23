#include "Functions.h"
#include <cmath>

using namespace std;

double Second(int n)
{
	double dva = 0;
	double sum = 0;

	for (int i = 1; i <= n; i++)
	{
		dva = 2;
		sum += step(i, 2) * step(dva, n - i);
	}
	return sum;
}
//n = 2
//Sn = 6 (expected 6)
//
//n = 15
//Sn = 196317 (expected 196317)
double step(double x, int n)
{
	for (int i = 0; i < n; i++)
	{
		double f = x;
		x *= x;
		x = f;
	}
	return x;
}

//double First(int n, int x)
//{
//    double i = 1;
//
//    double sum = 1;
//    double res = 1;
//
//    for (int k = 1; k <= n; k++)
//    {
//        i = -i * x / k;
//        sum += i;
//    }
//    return sum;
//}