// 6_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Functions.h";
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    /* проблема багатьох алгоритмів (тих самих вставкою() та швидких()) в тому,
        що найкращий час виконання роботи обмежується складністю O(n log n).
        timSort() має стабільні показники: O(n log n) - в гіршому та середньому випадках,
                                           O(n) - у кращому
       
        Фундамент цього алгоритму побудований на ідеї, що у масиві часто зустрічаються вже
        відсортовані підмасиви елментів. 

       Спочатку сортуйте невеликі підмасиви за допомогою insertion sort, 
       потім об’єднуєте їх за допомогою злиття сортування. 
       
       Ми розділяємо вхідний масив на підмасиви, відомі як Run. Ми сортуємо їх, 
       використовуючи insertion sort, а потім об’єднуємо підмасиви 
       за допомогою merge sort. Якщо розмір масиву менше за Run, тоді масив сортується 
       лише за допомогою insertion sort - він дуже дійсний на довжині до 32-елементів.*/


    int n1 = rand() % 40 + 1, n2 = rand() % 40 + 1, n3 = rand() % 40 + 1;
    double* massive1 = new double[n1];     double* massive1_2 = new double[n1];     //тут створюємо додаткові масиви 
    double* massive2 = new double[n2];     double* massive2_2 = new double[n2];     //для копіювання вхідних масивів
    double* massive3 = new double[n3];     double* massive3_2 = new double[n3];

    {
        fillArray(massive1, n1);
        for (int i = 0; i < n1; i++)
            cout << massive1[i] << '\t';   
        cout << '\n';

        for (int i = 0; i < n1; i++)
            massive1_2[i] = massive1[i];                               //copying the original massive to an another one

        /*for (int i = 0; i < n1; i++)                                 //
            cout << massive1_2[i] << '\t';                             //checking correctnes of copying the original massive
        cout << "\n\n";*/                                              //    
        //    int length1 = sizeof(massive1) / sizeof(massive1[0]);
        //    cout << length1 << '\n';

        timSort(massive1, n1);
        assert(checForAccuracy(massive1) && checkMassives(massive1, massive1_2)); //checkMassives(massive1, massive1_2) && 
 
        for (int i = 0; i < n1; i++)
            cout << massive1[i] << '\t';
        cout << "\n\n";
    }
    {
        fillArray(massive2, n2);
        for (int i = 0; i < n2; i++)
            cout << massive2[i] << '\t';
        cout << '\n';

        for (int i = 0; i < n2; i++)
            massive2_2[i] = massive2[i];

        timSort(massive2, n2);
        assert(checkMassives(massive2, massive2_2) && checForAccuracy(massive2));
        
        for (int i = 0; i < n2; i++)
            cout << massive2[i] << '\t';
        cout << "\n\n";
    }
    {
        fillArray(massive3, n3);
        for (int i = 0; i < n3; i++)
            cout << massive3[i] << '\t';
        cout << '\n';

        for (int i = 0; i < n3; i++)
            massive3_2[i] = massive3[i];

        timSort(massive3, n3);
        assert(checkMassives(massive2, massive2_2) && checForAccuracy(massive2));

        for (int i = 0; i < n3; i++)
            cout << massive3[i] << '\t';
        cout << '\n';
    }
}

/////////////////////////////////////////////////////////////////////////////////////
bool checkMassives(double* massive1, double* massive2)               //перевірка на рівну довжину вхідного та відсотованого масивів
{                                                                    //та на відповідність всіх елементів
    int length1 = sizeof(massive1) / sizeof(massive1[0]);
    int length2 = sizeof(massive2) / sizeof(massive2[0]);

    if (length1 == length2)
    {
        for (int i = 0; i < length1; i++)
            if (massive1[i] != massive2[i])
                return false;
    }
    else return false;
    return true;
}
/////////////////////////////////////////////////////////////////////////////////////
bool checForAccuracy(double* massive2)                               //перевірка на відсортованість відсортованого масиву
{
    int length2 = sizeof(massive2) / sizeof(massive2[0]);
    for (int i = 0; i < length2; i++)
    {
        if (massive2[i] > massive2[i + 1]) //massive2[i] != massive2[i + 1] || (?)
            return false;
    }
    return true;
}