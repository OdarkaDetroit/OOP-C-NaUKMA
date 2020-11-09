// 5_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Hornerr.h"

#include <iostream>
using namespace std;

int main()
{
    /*cout << "Enter n - the biggest stepen`: \n";
    cin >> n;*/
    //cout << "\n\n";
    int n = 1, n1 = 2, n2 = 4, n3 = 8, n4 = 16, n5 = 32;
    size_t size = n + 1, size1 = n1 + 1, size2 = n2 + 1, size3 = n3 + 1, size4 = n4 + 1, size5 = n5 + 1;
    double* coeff = new double[size]; 
    double* coeff1 = new double[size1];
    double* coeff2 = new double[size2];
    double* coeff3 = new double[size3];
    double* coeff4 = new double[size4];
    double* coeff5 = new double[size5];
    double x0 = -9, x = -3, x1 = -1, x2 = 0, x3 = 1, x4 = 3;

    fillArray(coeff, size);
    for (int i = 0; i < size; i++)
        cout << coeff[i] << '\t';
    cout << "result --> " << Horner(coeff, size, x0);
    cout << "\n\n";

    fillArray(coeff1, size1);
    for (int i = 0; i < size1; i++)
        cout << coeff1[i] << '\t';
    cout << "result --> " << Horner(coeff1, size1, x);
    cout << "\n\n";

    fillArray(coeff2, size2);
    for (int i = 0; i < size2; i++)
        cout << coeff2[i] << '\t';
    cout << "result --> " << Horner(coeff2, size2, x1);
    cout << "\n\n";

    fillArray(coeff3, size3);
    for (int i = 0; i < size3; i++)
        cout << coeff3[i] << '\t';
    cout << "result --> " << Horner(coeff3, size3, x2);
    cout << "\n\n";

    fillArray(coeff4, size4);
    for (int i = 0; i < size4; i++)
        cout << coeff4[i] << '\t';
    cout << "result --> " << Horner(coeff4, size4, x3);
    cout << "\n\n";

    fillArray(coeff5, size5);
    for (int i = 0; i < size5; i++)
        cout << coeff5[i] << '\t';
    cout << "result --> " << Horner(coeff5, size5, x4);
    cout << "\n\n";

}