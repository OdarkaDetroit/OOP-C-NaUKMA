#include "Functions.h"
#include <iostream>
using namespace std;

// 1. Проаналізуйте рекурсивну функцію піднесення до 
//    натурального степеня. Виконайте її тестування. 
//    Доповніть допоміжну функцію підрахунком 
//    кількості її викликів.

 //ADD LICHILNYK
void zet(double& y, double& x, unsigned int& k, int& rqP)
{
	if (k > 0)
	{
		rqP++;
		if (k % 2 == 1)
		{
			y *= x; 
			k--;
		}
		else
		{
			x *= x;
			k /= 2;
		}
		zet(y, x, k, rqP);
	}
}

double power(double x, unsigned int n)
{
	double y = 1;
	int rqP = 0;

	zet(y, x, n, rqP);
	cout << "By " << rqP << " steps: " << '\n';

	return y;
}

// Проаналізуйте рекурсивну програму обчислення чисел Фібоначчі.
// Виконайте її тестування.Доповніть допоміжну функцію 
// підрахунком кількості її викликів.


// Допоміжна функція
 //ADD LICHILNYK

void fib(double& f1, double& f2, unsigned int n, int& rqP)
{
	++rqP;
	if (n >= 2)
	{
		double f = f2; f2 += f1; f1 = f;
		fib(f1, f2, n - 1, rqP);
		//++rqP;
	}
};

double Fibonaci(unsigned int n)
{
	double f0 = 0, f1 = 1;
	switch (n)
	{
	case 0:
		return f0;
	case 1:
		return f1;
	default:
		int rqP = 0;
		fib(f0, f1, n, rqP);
		cout << "By " << rqP << " steps: " << '\n';
		return f1;
	}
};
//////////////////////////////////////////////////////////////////////////
//3. Використовуючи результати лабораторної роботи № 7, складіть швидку 
//   рекурсивну функцію обчислень чисел Фібоначчі. Доповніть допоміжну 
//   функцію підрахунком кількості її викликів.

struct Matrix2x2
{
	int _11, _12, _21, _22;
};

struct Vector2
{
	int _1, _2;
};

Matrix2x2 multiplyMatr(Matrix2x2& a, Matrix2x2& b)
{
	  Matrix2x2 res;
	  res._11 = a._11* b._11 + a._12 * b._21;
	  res._12 = a._11* b._21 + a._12 * b._22;
	  res._21 = a._21* b._11 + a._22 * b._21;
	  res._22 = a._21* b._21 + a._22 * b._22;

	//a = res;
	return res;
}
// Множення матриці на вектор
Vector2 multiplyMatrVect(Matrix2x2& a, Vector2& v )
{
	Vector2 res;

	res._1 = a._11 * v._1 + a._12 * v._2;
	res._2 = a._21 * v._1 + a._22 * v._2;

	return res;
}

Matrix2x2 quickPower(Matrix2x2& first, int n, int& rqP)
{
	++rqP;

	Matrix2x2 second = { 1, 1, 1, 0 };

	if (n == 0 || n == 1) return second;

	//	if (n > 0)
		//{
	quickPower(first, n / 2, rqP);

	multiplyMatr(first, first);
	if (n % 2 != 0)
		multiplyMatr(first, second);

	return first;
}

int quickFib(int n, int& rqP)
{
	Matrix2x2 fibMatrix = { 1, 1, 1, 0 };
	Vector2 fibVector = { 1, 0 };

	Matrix2x2 fibRes = quickPower(fibMatrix, n - 1, rqP);
	cout << "by " << rqP << " steps: " << '\n';
	return multiplyMatrVect(fibRes, fibVector)._1;
}
