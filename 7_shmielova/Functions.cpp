#include "Functions.h"

#include <cmath>


struct Matrix2x2
{
    int _11, _12, _21, _22;
};

struct Vector2
{
    int _1, _2;
};

const Matrix2x2 operator* (const Matrix2x2& a, const Matrix2x2& b) 
{
    // _11 _12
    // _21 _22
    Matrix2x2 res = { 
        a._11 * b._11 + a._12 * b._21,
        a._11 * b._21 + a._12 * b._22,
        a._21 * b._11 + a._22 * b._21,
        a._21 * b._21 + a._22 * b._22 
    };
    return res;
}
// Множення матриці на вектор
const Vector2 operator* (const Matrix2x2& a, const Vector2& v)
{
    Vector2 res = { 
        a._11 * v._1 + a._12 * v._2, 
        a._21 * v._1 + a._22 * v._2 
    };
    return res;
}

const Matrix2x2 unitMatrix = { 1,0,0,1 };

Matrix2x2 quickPower(Matrix2x2 first, int n, Matrix2x2 second)
{
    if (n == 0) return second;
    else if (n % 2 == 0) return quickPower(first * first, n / 2, second);
    else if (n % 2 != 0) return quickPower(first, n - 1, first * second);

}

int quickFib(int n) 
{
    Matrix2x2 fibMatrix = { 1,1,1,0 }; 
	Vector2 fibVector = { 1, 0 };
    Vector2 fibRes = quickPower(fibMatrix, n - 1, unitMatrix) * fibVector;
    return fibRes._1;
}




