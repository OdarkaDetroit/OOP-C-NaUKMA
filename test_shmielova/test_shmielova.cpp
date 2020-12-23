// test_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Functions.h"
using namespace std;


int main()
{
	{// 1st TASK PERFORMANCE
		cout << "1st task|||||||||||||||\n\n";

		int x1 = 0, x2 = 1;
		cout << "x=0  =>  " << (x1 == 0 ? 1 : 0) << '\n';
		cout << "x=1  =>  " << (x2 == 0 ? 1 : 0) << "\n\n";
	}
	{// 2nd TASK PERFORMANCE
		cout << "2nd task|||||||||||||||\n\n";
		
		int n1 = 0, n2 = 2, n3 = 3;
		double x1 = 2, y1 = 3;

		cout << "x = 2, y = 4, n = 0  =>  " << second(x1, y1, n1) << '\n';
		cout << "x = 2, y = 4, n = 2  =>  " << second(x1, y1, n2) << '\n';
		cout << "x = 2, y = 4, n = 4  =>  " << second(x1, y1, n3) << "\n\n";
	}

	{// 3rd TASK PERFORMANCE
		cout << "3rd task|||||||||||||||\n\n";

		unsigned int n = 0;

		cout << "x = 0  =>  " << third(n) << "\n\n";
	}

	{// 4th TASK PERFORMANCE
	std::cout << "4th task|||||||||||||||\n\n";

	char word1[] = "Inextremis";     
	char word2[] = "Hello World!";	
	char word3[] = "do w i d z e n i a";		

	foth(word1);
	foth(word2);
	foth(word3);
	cout << "\n\n";
	}

	{// 5th TASK PERFORMANCE
		cout << "5th task|||||||||||||||\n\n";

		Struct one{ "C++ forever", seventh(one.arr) };
		Struct two{ "BTS", seventh(two.arr) };

		cout << (one == two) << '\n';
		cout << (one == one) << '\n';
		cout << (two == two) << "\n\n";
	}

	{// 6th TASK PERFORMANCE
		cout << "6th task|||||||||||||||\n\n";

		Struct one{"C++ forever", seventh(one.arr)};
		Struct two{"BTS", seventh(two.arr)};
		Struct three{"Yes!=no", seventh(three.arr)};
		Struct foer{"W", seventh(three.arr)};

		cout << (one < two) << '\n';
		cout << (one < three) << '\n';
		cout << (one < foer) << "\n\n";
	}

	{// 7th TASK PERFORMANCE
		cout << "7th task|||||||||||||||\n\n";

		const char* arr = "It is a procedural proframming test.";
		const char* arr1 = "2020 is a hard year...";
		cout << "result  =>  " << seventh(arr1) << '\n';
		cout << "result  =>  " << seventh(arr) << "\n\n";
	}

	{// 8th TASK PERFORMANCE
		cout << "8th task|||||||||||||||\n\n";

		Struct one{ "C++ forever", seventh(one.arr) };
		Struct two{ "Yell", seventh(two.arr) };

		cout << eigth(one, two) << '\n';
		cout << eigth(two, one) << "\n\n";

	}
	{// 9th TASK PERFORMANCE
		cout << "9th task|||||||||||||||\n\n";
		cout << "lexicographic sorting :\n";

		Struct full[]
		{
		{ "C++ forever", strlen("C++ forever")},
		{ "Yell", strlen("Yell") },
		{ "BELCOME", strlen("WELCOME") }
		};

		Struct full1[]
		{
		{ "C++ forever", strlen("C++ forever")},
		{ "Yell", strlen("Yell") },
		{ "BELCOME", strlen("WELCOME") }
		};

		ninth_lex(full, 3);
		cout << "\n\n";

		cout << "length sorting :\n";
		ninth_len(full1, 3);
		cout << "\n\n";

	}
	{// 10th TASK PERFORMANCE
		cout << "10th task|||||||||||||||\n\n";

		double ex1[] = { 22, 3, 32, 1};
		char ex2[] = {"good"};

		cout << "double massive: \n";
		tenth(ex1);
		cout << "\n\n";
		cout << "char massive: \n";
		tenth(ex2);
		cout << "\n\n";
	}
}
