// 3_shmielova_pp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Functions.h"

using namespace std;

double x1 = 1;
double eps1 = 0.00001;

double x2 = 1;
double eps2 = 0.00001;

double x3 = -10;
double eps3 = 0.00001;



int main()
{
	{//TESTING gaus()
		for (int i = 0; i < 10; i++)
		{
			cout << "Result of gauss calculating: " << gaus(x1, eps1) << '\n';
			++x1;
		}
	}
	cout << "\n\n";
	{//TESTING ex_first()
		for (int i = 0; i < 10; i++)
		{
			cout << "Result of exponenta calculating: " << ex_first(x2, eps2) << '\n';
			++x2;
		}
	}
	cout << "\n\n";
	{//TESTING ex_second()
		for (int i = 0; i < 10; i++)
		{
			cout << "Result of exponenta(ee) calculating: " << ex_second(x3, eps3) << '\n';
			++x3;
		}
	}
}

