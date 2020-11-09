#include "Functions.h";
#include <limits>
#include <cmath>
#include <algorithm> 

using namespace std;

void fillArray(double* massive, int n)
{
	for (int i = 0; i < n; ++i)
		massive[i] = rand();
	return;
}
/////////////////////////////////////////////////////////////////////////////////////
void insertionSort(double* massive, int left, int right)
{
    for (int i = left + 1; i <= right; i++)  
    {
        double temp = massive[i];
        int j = i - 1;

        while (j >= left && massive[j] > temp)
        {
            massive[j + 1] = massive[j];
            --j;
        }
        massive[j + 1] = temp;
    }
}
/////////////////////////////////////////////////////////////////////////////////////
void merge(double* massive, int a, int b, int c)
{
    int nl, nr, i, j, k;

    nl = b - a + 1;         
    nr = c - b;             

    double* larr = new double[nl];
    double* rarr = new double[nr];

    for (int i = 0; i < nl; i++)
        larr[i] = massive[a + i];
    for (int j = 0; j < nr; j++)
        rarr[j] = massive[b + j + 1];

    i = 0;
    j = 0;

    for (k = a; i < nl && j < nr; k++)
    {
        if (larr[i] < rarr[j])
        {
            massive[k] = larr[i++];
        }
        else
        {
            massive[k] = rarr[j++];
        }
    }

    while (i < nl)
    {     
        massive[k++] = larr[i++];
    }
    while (j < nr)
    {     
        massive[k++] = rarr[j++];
    }
    //return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
void timSort(double* massive, int n)
{
    const int RUN = 32;

    for (int i = 0; i < n; i += RUN)
        insertionSort(massive, i, min((i + 31), (n - 1)));

    for (int size = RUN; size < n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            merge(massive, left, mid, right);
        }
    }
}
