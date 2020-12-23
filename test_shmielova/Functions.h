#pragma once
#include <string>

double second(double x, double y, int n);

unsigned int third(unsigned int n);

typedef struct Struct
{
	const char* arr;
	size_t len; 
};

void foth(char* word);

bool operator==(Struct one, Struct two); //5

bool operator<(Struct& one, Struct& two); //6

int seventh(const char* arr);

bool eigth(Struct two, Struct one);

void ninth_lex(Struct* massive, int size);

void ninth_len(Struct* massive, int size);

template <typename T>
void tenth(T* massive)
{
    int left = 0;
    int size = sizeof(massive);

    for (int i = left + 1; i < size; i++)
    {
        T temp = massive[i];
        int j = i - 1;

        while (j >= left && temp < massive[j])
        {
            massive[j + 1] = massive[j];
            --j;
        }
        massive[j + 1] = temp;
    }
    for (int i = 0; i < size; i++)
        std::cout << massive[i] << '\n';
}