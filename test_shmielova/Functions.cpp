#include <iostream>
#include <cassert>

#include "Functions.h"

using namespace std;

double second(double x, double y, int n) 
{
    double coef = 0;
    
    coef += pow(x, pow(2, n)) * y;

    for (int i = 1; i < n; i++) 
    {
        x /= sqrt(x);
        y *= y;
        coef += x * y;
    }
    //assert(coef == ); not rec*
    return coef;
}

unsigned int third(unsigned int n)
{
    unsigned int res = 0;
    res = ~n;
    assert(res == 0xffffffff-n);
    return res;
}

void foth(char* word)
{
    const int len = seventh(word);

    for (int i = 0; i < len; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            word[i] += 'z' - 'Z';
            continue;
        }
        if (word[i] >= 'a' && word[i] <= 'z')   //else 
        {
            word[i] += 'Z' - 'z';
            continue;
        }
    }
    std::cout << word << '\n';;

}

bool operator==(Struct one, Struct two)
{
    if (one.len != two.len)
    {
        for (int i = 0; i < one.len; i++)
        {
            if (one.arr[i] != two.arr[i])
            {
                break;
                return false;
            }
        }
        return false;
    }

    else
    {
        assert(one.len == two.len);
        return true;
    }
}

bool operator<(Struct &one, Struct &two)
{
    int i = 0;
    while (one.arr[i] && two.arr[i])
    {
        char one_arr = one.arr[i],
             two_arr = two.arr[i];

      if (one_arr > 'A' && one_arr < 'Z')
            one_arr += 'z' - 'Z';

      if (two_arr > 'A' && two_arr < 'Z')
            two_arr += 'z' - 'Z';

      if (one.arr[i] < two.arr[i])
          return true;
      if (one.arr[i] > two.arr[i])
          return false;
         ++i;
    }
    if ((!one.arr[i] && !two.arr[i]))
    {
        return false; 
    }
    assert(one.len < two.len);
    return !one.arr[i];
}

int seventh(const char* arr)
{
    int len = 0;
    int i = 0;
    while(arr[i] != NULL)
    {
        ++len;
        ++i;
    }
    return len;
}

bool eigth(Struct two, Struct one)
{
    if (one.len > two.len)
    {
        for (int i = 0; i < two.len; i++)
        {
            if (two.arr[i] < one.arr[i])
                return true;
        }
        return true;
    }
    else
        return false;
}

void ninth_lex(Struct* massive, int size)
{
    int left = 0;

    for (int i = left + 1; i < size; i++)
    {
        Struct temp = massive[i];
        int j = i - 1;

        while (j >= left && temp < massive[j])
        {
            massive[j + 1] = massive[j];
            --j;
        }
        massive[j + 1] = temp;
    }
    for (int i = 0; i < size; i++)
        cout << massive[i].arr << '\n';
}
void ninth_len(Struct* massive, int size)
{
    int left = 0;

    for (int i = left + 1; i < size; i++)
    {
        Struct temp = massive[i];
        int j = i - 1;

        while (j >= left && eigth(temp, massive[j]))
        {
            massive[j + 1] = massive[j];
            --j;
        }
        massive[j + 1] = temp;
    }
    for (int i = 0; i < size; i++)
        cout << massive[i].arr << '\n';
}

