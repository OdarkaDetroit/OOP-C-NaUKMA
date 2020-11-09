// 7_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Functions.h"
using namespace std;

int main()
{
    int n = 2; // n1 = 3, n2 = 4, n3 = 5, n4 = 6, n5 = 7;

    for (int i = 0; i < 10; i++)
    {
        cout << "for " << n << " the last fibonacci number is: " << '\n';
        cout << quickFib(n) << "\n\n";
        n += 2;
    }
    
   /* cout << "for " << n1 << " the last fibonacci number is: " << '\n';
    cout << quickFib(n1) << "\n\n";
    cout << "for " << n2 << " the last fibonacci number is: " << '\n';
    cout << quickFib(n2) << "\n\n";
    cout << "for " << n3 << " the last fibonacci number is: " << '\n';
    cout << quickFib(n3) << "\n\n";
    cout << "for " << n4 << " the last fibonacci number is: " << '\n';
    cout << quickFib(n4) << "\n\n";
    cout << "for " << n5 << " the last fibonacci number is: " << '\n';
    cout << quickFib(n5) << "\n\n";*/

}



