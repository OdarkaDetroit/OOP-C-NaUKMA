// 9_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Functions.h"
#include <cassert>
#include <cmath>

# define M_PI 3.14159265358979323846

using namespace std;

// 1- sin(x) = x, [-1, 1];
// 2- sin(x) = 0, [π - 1, π];
// 3- ln(x) = 1, [2, 3];
// 4- exp(x) = 2 - x, [0, 2] 

double sin1(double x) { 
	return sin(x)-x; 
}
double sin2(double x) { 
	return sin(x); 
}
double ln(double x) { 
	return log(x)-1; 
}
double expon(double x) { 
	return exp(x)-2+x; 
}


int main()
{
	double a = 0; 
	double b = 0;
	double eps = 0.0001;

	cout << "sin(x) = x, [-1, 1]"; 
	cout << "    ";
	a = -1; b = 1; 
	cout << dichotomy(sin1, a, b, eps) << endl;

	cout << "sin(x) = 0, [π - 1, π]";
	cout << "    ";
	a = M_PI-1; b = M_PI;
	cout << dichotomy(sin2, a, b, eps) << endl;

	cout << "ln(x) = 1, [2, 3]";
	cout << "    ";
	a = 2; b = 3;
	cout << dichotomy(ln, a, b, eps) << endl;

	cout << "exp(x) = 2 - x, [0, 2]";
	cout << "    ";
	a = 0; b = 2;
	cout << dichotomy(expon, a, b, eps) << endl;
}
