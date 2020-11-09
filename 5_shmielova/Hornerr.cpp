#include "Hornerr.h"
#include <cassert>
#include <iostream>

void fillArray(double* coeff, size_t size)
{
	for (int i = 0; i < size; ++i)
		coeff[i] = 0.1 * (rand() % 190 - 90.0);
	
	/*for (int i = 0; i < size; i++)
		std::cout << coeff[i] << "\t";
	std::cout << "\n\n";*/
	return ;
}
double sum(double* coeff, size_t size, int sign)
{
	double res = 0;
	if (sign == 1)
	{
		for (int j = 0; j < size; j++)
		{
			res += coeff[j];
		}
	}
	else if (sign == -1)
	{
		for (int j = 0; j < size; j++)
		{
			sign *= -1;
			res += sign * coeff[j];
		}
	}
	return res;
}
double Horner(double* coeff, size_t size, double x)
{
	double result = coeff[0];

	for (int i = 1; i < size; i++)
	{
		//int j = *(coeff + i);
		result = result * x + coeff[i];
	}

	assert(((x == 1) || (x == -1)) ? (result == sum(coeff, size, x)) : true);

	return result;

}
