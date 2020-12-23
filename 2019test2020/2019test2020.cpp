// 2019test2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Functions.h"

using namespace std;

int main()
{
    {// 9th TASK PERFORMANCE
        cout << "task 9\n\n";

        const size_t n = 4;
        double x = 2;
        double arr[n];

        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 100 + 1.0;
            cout << arr[i] << '\t';
        }
        Polynomial p = { arr, n }; 
        Polynomial p1 = { arr, n };

        double arrCop[n]; 
        for (int i = 0; i < n; i++)
        {
            arrCop[i] = arr[i];
        }

        cout << nine_f(p, x) << '\n'; x = 2;
        cout << nine_s(p1, x) << '\n';
    }


}

