// 2017-2018.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Functions.h"
using namespace std;

int main()
{
	{ // 1st task performance
		double z = 1, x = 2, y = 3; //rand() % 100 + 1;
		cout << "1 task\n\n";
		cout << "result: ";
		first(x, y, z);
		//double w = 0;
		//cout << (w = (z > ((x > y) ? x : y) ? z : ((x > y) ? x : y))) << "\n\n";
	}
	{// 2nd task performance
		int x = 9, y = 3;
		cout << "__________________\n";
		cout << "2 task\n\n";
		cout << "result: " << second(x, y) << "\n\n";
	}
}
