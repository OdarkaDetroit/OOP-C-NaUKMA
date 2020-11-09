// 4_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include "Functions.h"

using namespace std;

int main() 
{
   cout.precision(15);
   double a = 0.8, b = 6;
   cout << "Result of agm(): " << agm(a, b) << "\n\n";

   cout.precision(15);
   double a1 = 2, b1 = 8;
   cout << "Result of agm(): " << agm(a1, b1) << "\n\n";

   cout.precision(15);
   double a2 = 2, b2 = 6.9;
   cout << "Result of agm(): " << agm(a2, b2) << "\n\n";

   cout.precision(15);
   double a3 = 0.8, b3 = 6.9;
   cout << "Result of agm(): " << agm(a3, b3) << "\n\n";

   double a5 = 5, b5 = 50;
   for (int i = 0; i < 6; i++)
   {
       cout << "Result of agm(): " << agm(a5, b5) << "\n\n";
       a5 += 5; b5 += 50;
   }
   //PLEASE, PAY ATTENTION HERE
   //можна перевірити випадок, де перше число більше за друге
   /*double a4 = 5, b4 = 2;
   cout << "Result of agm(): " << agm(a4, b4) << '\n';*/
}
