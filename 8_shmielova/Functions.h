#pragma once

struct Vector2;
struct Matrix2x2;

double power(double x, unsigned int n);
double Fibonaci(unsigned int n);
int quickFib(int n, int& rqP);
Vector2 multiplyMatrVect(Matrix2x2& a, Vector2& v); //Vector2 multiplyMatrVect( Matrix2x2 a,  Vector2 v)
Matrix2x2 quickPower(Matrix2x2& first, int n, int& rqP);
Matrix2x2 multiplyMatr(Matrix2x2& a, Matrix2x2& b);
