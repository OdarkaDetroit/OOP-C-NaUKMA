#include <iostream>

#include "Functions.h"

using namespace std;

int main()
{
    int rP = 0;
    int cP = 0; 
    int rqP = 0; 
    int cqP = 0;

    { // testing "cycPower()"

        cout << "///////////////////Testing cyPower() \n\n";
        double x = 1;
        int k = 0;

        for (int i = 1; i < 20; i++)
        {
            cout << "original result: " << pow(x, k) << '\n';
            cout << "my function result: " << cycPower(x, k, cP) << '\n';
            cout << "Counter: " << cP << "\n\n";
            x += 2;
            ++k;
        }
    }
    { // testing "recPower()"

        cout << "///////////////////Testing recPower() \n\n";
        double x = 1;
        int k = 0;

        for (int i = 1; i < 20; i++)
        {
            cout << "original result: " << pow(x, k) << '\n';
            cout << "my function result: " << recPower(x, k, rP) << '\n';
            cout << "Counter: " << rP << "\n\n";
            x += 2;
            ++k;
        }
    }
    { // testing "recQuickPower()"

        cout << "///////////////////Testing recQuickPower() \n\n";
        double x = 1;
        int k = 0;

        for (int i = 1; i < 20; i++)
        {
            cout << "original result: " << pow(x, k) << '\n';
            cout << "my function result: " << recQuickPower(x, k, rqP) << '\n';
            cout << "Counter: " << rqP << "\n\n";
            x += 2;
            ++k;
        }
    }
    { // testing "cycQuickPower()"

        cout << "///////////////////Testing cycQuickPower() \n\n";
        double x = 1;
        int k = 0;

        for (int i = 1; i < 20; i++)
        {
            cout << "original result: " << pow(x, k) << '\n';
            cout << "my function result: " << cycQuickPower(x, k, cqP) << '\n';
            cout << "Counter: " << cqP << "\n\n";
            x = +2;
            ++k;
        }
    }
}