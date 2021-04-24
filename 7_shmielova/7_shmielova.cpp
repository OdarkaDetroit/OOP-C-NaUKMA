// 7_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "String.h"


#include <iostream>
using namespace std;


int main()
{
    {
        String s("Tra-ta-ta");
        const char* ps = s.c_str();
        cout << s + ps << endl;
        cout << ps + s << endl;
        cout << ':' << (s = ps) << '.' << endl;
        cout << ':' << (s == ps) << '.' << endl;
        cout << ':' << (ps == s) << '.' << endl;
    }

    {
        //TESTING 6 constructors types

        cout << "_______________Testing constructors\n\n";

        String s("First string");
        string a1 = "Second string";
        String s1(a1);
        const char* a2 = "Third string";
        String s2(a2);
        char a3 = '3';
        String s3(a3);
        String s4(s3, 11);
        String s5();

        {//TESTING showing 6 constructors types
            cout << "\n_______________Show constructors work:\n\n";
            cout << "s = " << s;
            cout << "\ns1 = " << s1;
            cout << "\ns2 = " << s2;
            cout << "\ns3 = " << s3;
            cout << "\ns4 = " << s4 << "\n";
        }

        {//TESTING empty() and cclear() methods
            if (!s3.empty())
            {
                cout << "Deleting s3...\n";
                s3.clear();
                cout << "\nDeleted s3 --> " << s3 << '\n';
                try
                {
                    cout << "\nlet's try to create exceptions\n";
                    char* ch = 0;
                    String s(ch);
                    delete[] ch;
                }
                catch (String::BadString e) { e.diagnose(); }

                try { s3[5]; }
                catch (String::BadIndex b) { b.diagnose(); }

            }
        }

        const char* a21 = "Next string #1";
        const char* a22 = "Next string #2";
        char* a23;
        char a32 = 'a';
        char a33 = 'b';
        char a34;
        String word_1("one");
        String word_2("twelve");
        String word_3;

        {//TESTING different operators
            cout << "\n_______________Crested new objects for operators testing\n\n";

            cout << "word_1 = " << word_1 << "\nword_2 = " << word_2 << "\nword_3 = " << word_3;
            cout << "\na21 = " << a21 << "\na22 = " << a22;
            cout << "\na32 = " << a32 << "\na33 = " << a33 << "\n\n";

            cout << "\n_______________<\t<=\t>\t>=\n\n";
            //cout << boolalpha;
            cout << "-----String type\n";
            cout << word_1 << " < " << word_2 << "\t" << (word_1 < word_2) << '\n';
            cout << word_2 << " <= " << word_1 << "\t" << (word_2 <= word_1) << '\n';
            cout << word_1 << " > " << word_2 << "\t" << (word_1 > word_2) << '\n';
            cout << word_2 << " >= " << word_1 << "\t" << (word_2 >= word_1) << '\n';

            cout << "-----char* type\n";
            cout << a21 << " < " << a22 << "\t" << (a21 < a22) << '\n';
            cout << a22 << " <= " << a21 << "\t" << (a22 <= a21) << '\n';
            cout << a21 << " > " << a22 << "\t" << (a21 > a22) << '\n';
            cout << a22 << " >= " << a21 << "\t" << (a22 >= a21) << '\n';

            cout << "-----char type\n";
            cout << a32 << " < " << a33 << "\t" << (a32 < a33) << '\n';
            cout << a33 << " <= " << a32 << "\t" << (a33 <= a32) << '\n';
            cout << a32 << " > " << a33 << "\t" << (a32 > a33) << '\n';
            cout << a33 << " >= " << a32 << "\t" << (a33 >= a32) << '\n';


            cout << "\n_______________==\n\n";

            cout << "-----String type\n";
            cout << word_1 << " == " << word_2 << '\t' << (word_1 == word_2) << '\n';

            cout << "-----char* type\n";
            cout << a21 << " == " << a22 << '\t' << (a21 == a22) << '\n';

            cout << "-----char type\n";
            cout << a32 << " == " << a33 << '\t' << (a32 == a33) << '\n';


            cout << "\n_______________+=\t+\n\n";
            word_3 = word_1 + word_2;
            cout << "word_3 (after = word_1 + word_2) --> " << word_3 << '\n';
            word_1 += word_2;
            cout << "word_1 (after word_1 =+ word_2) --> " << word_1 << '\n';
            a32 += a33;
            cout << "a32 (after a32 =+ a33) --> " << a32 << '\n';

        }
    }
    system("pause");
    return 0;
}