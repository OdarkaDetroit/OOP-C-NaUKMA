// 8_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Functions.h"
using namespace std;

int main()
{
	{
		cout << "The 1st task performance: \n\n";

		int rqP = 0, x = 2, n = 1;
		cout << power(x, n) << '\n';
		rqP = 0, x = 4, n = 2;
		cout << power(x, n) << '\n';
		rqP = 0, x = 6, n = 3;
		cout << power(x, n) << '\n';
		rqP = 0, x = 8, n = 4;
		cout << power(x, n) << "\n\n";
	}
	{
		cout << "The 2nd task performance: \n\n";

		int n = 2, rqP = 0;
		for (int i = 0; i < 5; i++)
		{
			cout << Fibonaci(n, rqP) << '\n';
			++n;
		}
		cout << '\n';
	}
	{
		cout << "The 3rd task performance: \n\n";

		int n = 1, rqP = 0;
		cout << quickFib(n, rqP) << '\n';
		n = 2, rqP = 0;
		cout << quickFib(n, rqP) << '\n';
		n = 3, rqP = 0;
		cout << quickFib(n, rqP) << '\n';
		n = 5, rqP = 0;
		cout << quickFib(n, rqP) << '\n';
		n = 8, rqP = 0;
		cout << quickFib(n, rqP) << '\n';
	}
}
