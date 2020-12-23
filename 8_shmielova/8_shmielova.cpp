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
		for (int j = 0; j < 10; j++)
		{
			cout << power(x, n) << '\n';
			cout << "checking by defoult: " << pow(x, n) << "\n\n";
			x += 2;
			n += 2;
		}
		cout << "\n\n";
	}
	{
		cout << "The 2nd task performance: \n\n";

		int n = 2, rqP = 0;
		for (int i = 0; i < 10; i++)
		{
			cout << Fibonaci(n) << '\n';
			n+=3;
		}
		cout << '\n';
	}
	{
		cout << "The 3rd task performance: \n\n";

		//int n = 1, rqP = 0;
		//cout << quickFib(n, rqP) << '\n';
		//n = 2, rqP = 0;
		//cout << quickFib(n, rqP) << '\n';
		//n = 3, rqP = 0;
		//cout << quickFib(n, rqP) << '\n';
		//n = 5, rqP = 0;
		//cout << quickFib(n, rqP) << '\n';
		//n = 1024, rqP = 0;
		//cout << quickFib(n, rqP) << '\n';


		int n = 1, rqP = 0;
		for (int l = 0; l < 10; l++)
		{
			cout << quickFib(n, rqP) << '\n';
			n += 3;
			rqP = 0;
		}
	}
}
