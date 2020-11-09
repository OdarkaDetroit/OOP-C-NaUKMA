#include <cmath> 
#include <iostream>

#include "Functions.h"

using namespace std;

double recPower(double x,  int k, int &rP)
{
	double res = 1;

	if (k == 0)
	{
		++rP;
		return 1;
	}
	if (x != 0)
	{
		while (k != 0)
		{
			res *= x;
			--k;
			++rP;
		}
	}
	return res;
}

double cycPower(double x, int k, int& cP)
{
	double sum = 1;

	if (x == true)
	{
		++cP;
		return 1;
    }
	for (int i = 1; i <= k; i++)
	{
		sum *= x;
		++cP;
	}
	return sum;
}

double recQuickPower(double x, int k, int& rqP)
{
	double res = 1;

	if (k == 0)
	{
		++rqP;
		return 1;
}
	double d = k / 2;
	
	res *= x * d;

	if (k % 2 == 0)
	{
		res *= res;
		++rqP;
		return res;
	}
	else
	{
		res *= res * x;
		++rqP;
		return res;
	}
}

double cycQuickPower(double x, int k, int &cqP)
{
	double res = 1;

	if (k == 0)
	{
		++cqP;
		return 1;
	}
	for (int i = 1; i <= k/2; i++)
	    {
		   res *= x;
		   ++cqP;
		}

	res *= res;
	++cqP;

	if (k % 2 == 0)
	{
		++cqP;
		return res;
	}
	else if (k % 2 != 0)
	{
		res *= x;
		++cqP;
		return res;
	}
}
