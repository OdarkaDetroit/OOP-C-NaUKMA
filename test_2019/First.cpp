#include "Functions.h"
#include <cmath>

using namespace std;

// 1. Для змінної unsigned int n спростити 
//    вираз n = ~n ? n : 0xFFFFFFFF.

double First(unsigned int n)
{
	//~n == 0 ? 0xFFFFFFFF : n;
	int n_different = ~n;
	if (n == n_different)
		return n;
	else return 0xFFFFFFFF;
}
