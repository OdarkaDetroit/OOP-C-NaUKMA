// 9_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array.h"
#include "Time.h"

using namespace std;

int main()
{
	{//Testing DOUBLE
		cout << " -=-=-=-=-=-=- Test array with double -=-=-=-=-=-=- \n\n";
		try
		{
			Array<10, double> arr_d;

			for (int i = 0, len = arr_d.size(); i < len; ++i)
			{
				arr_d[i] = (i + 0.1) * 2;
				cout << "arr_d[" << i << "] -- " << arr_d[i] << '\n';
			}
			cout << arr_d[10] << '\n';
		}
		catch (const Array<10, double>::BadArray& badArray)
		{
			badArray.diagnose();
		}
	}

	{//Testing CHAR
		cout << "\n\n -=-=-=-=-=-=- Test array with char -=-=-=-=-=-=- \n\n";
		try
		{
			Array<5, char> arr_c;

			arr_c[0] = 'c';
			arr_c[1] = 'h';
			arr_c[2] = 'a';
			arr_c[3] = 'r';

			for (int i = 0, len = arr_c.size(); i < len; ++i)
			{
				cout << "arr_c[" << i << "] -- " << arr_c[i] << '\n';
			}
			cout << arr_c[10] << '\n';
		}
		catch (Array<5, char>::BadArray& badArray)
		{
			badArray.diagnose();
		}
	}

	{//Testing TIME
		cout << "\n\n -=-=-=-=-=-=- Test array with Time -=-=-=-=-=-=- \n\n";

		try
		{
			Array<5, Time> arr_t;
			const Time t1(1, 1, 1);
			for (size_t i = 0; i < arr_t.size(); i++)
			{
				arr_t[i] = Time((i + 0.1) * 2, (i + 0.1) * 1.5, (i + 0.2) * 2);
			}

			for (size_t i = 0; i < arr_t.size(); i++)
			{
				cout << "arr_t[" << i << "] -- " << arr_t[i] << '\n';
			}
		}
		catch (const Array<5, Time>::BadArray& badArray)
		{
			badArray.diagnose();
		}
	}

	{//Testing methods and operators
		cout << "\n\n -=-=-=-=-=-=- Test move and operator '=' -=-=-=-=-=-=- \n\n";

		Array<3, Time> arr_t;

		const Time t1(20, 10, 5), t2(2, 4, 6);

		arr_t[0] = t1;
		arr_t[1] = t2;

		Array<3, Time> arr_t_2 = move(arr_t);

		for (size_t i = 0; i < arr_t_2.size(); i++)
		{
			cout << "arr_t_2[" << i << "] -- " << arr_t_2[i] << '\n';
		}

		cout << "\n*created empty arr_t_3*\n -->";
		Array<3, Time> arr_t_3;

		arr_t_3 = move(arr_t_2);
		cout << "___after move(arr_t_2):\n";
		for (size_t i = 0; i < arr_t_3.size(); i++)
		{
			cout << "arr_t_3[" << i << "] -- " << arr_t_3[i] << '\n';
		}

		arr_t_3[0] = Time(1, 2, 3);
		arr_t = move(arr_t_3);

		for (size_t i = 0; i < arr_t.size(); i++)
		{
			cout << "arr_t[" << i << "] -- " << arr_t[i] << '\n';
		}
	}

	return 0;
}
