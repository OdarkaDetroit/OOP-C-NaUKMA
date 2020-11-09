#include <iostream>
#include <cmath>
#include "Functions.h"

using namespace std;

double gaus(double x, double eps)
{
    double t = x;
    double k = 0;
    double sum = t;

    do
    {
        sum += (t *= (-1) * x * x * (2 * (k++) + 1) / (2 * (k++) + 3) / (1 + (k++)));
    } while (fabs(t) > eps);

    return sum;
}
double ex_first(double x, double eps)
{
   double sum = 1;
   double t = 1;
   int n = 1;

   while (fabs(t) > eps) {
       sum += (t *= ((double)x) / n++);
   }
   return sum;

}
double ex_second(double x, double eps)
{
    double y, n, res;
    double e = 2.71828;
    if (x >= 0)
    {
        y = modf(x, &n); //y - ",****", n - "**,"
        res = recPower(e, n) * ex_first(y, eps);
    }
    else
    {
        res = 1;
        x *= -1;
        res /= ex_first(x, eps);
    }
    return res;
}

double recPower(double x, double k)
{
    double res = 1;

    if (k == 0)
    {
        return 1;
    }
    if (x != 0)
    {
        while (k != 0)
        {
            res *= x;
            --k;
        }
    }
    return res;
}