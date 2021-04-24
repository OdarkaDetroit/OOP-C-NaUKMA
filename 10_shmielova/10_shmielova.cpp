// 10_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Sequence.h"
#include "String.h"

using namespace std;

int main()
{
	{
		cout << "-=-=-=-=-=-=-Creating double type sequence-=-=-=-=-=-=-\n\n";

		Sequence<double> s_zero(0);
		Sequence<double> s(1);
		
		cout << "s_zero(0) be like: " << s_zero;

		cout << "Before adding:\n" << s;
		cout << "\n_______Adding new elements...\n";

		for (int i = 0; i < 2; ++i)
		{
			s.add((i + 20.1)*2.5);
		}

		cout << "\n_______After adding:\n" << s;

		s.remove(0);
		cout << "\n_______After removing first element:\n" << s;

		s.clear();
		system("pause");
	}
	{
		cout << "\n\n-=-=-=-=-=-=-Creating int type sequence-=-=-=-=-=-=-\n";
		
		Sequence<int> s(5);
		
		cout << "\n_______Sequence before adding:\n" << s;
		for (auto i = 0; i < 9; ++i)
		{
			s.add(i);
		}
		cout << "\n_______Sequence after adding (add() method):\n" << s << '\n';

		for (int i = 0; i < 2; ++i)
		{
			s.remove(i);
		}
		cout << "\n_______Remove first 2 elements (remove() method): " << s << '\n';

		cout << "\n_______Sequence after inserting (insert() method):\n" << s;
		s.insert(10, 0);
		cout << s << '\n';

		cout << "\n_______Element 5 is in the sequence (contains() method)?\n";
		cout << s.contains(5) ? "Element 5 in sequence\n" : "Element 5 not in sequance\n";

		cout << "\n_______Sequance is full (full() method)?\n";
		cout << s.full() ? "Sequence sequance is full\n" : "Sequence sequance is not full\n";

		cout << "\n_______Cut():\n";
		s.cut();
		cout << s << '\n';

		s.clear();
		cout << "\n_______Clear():\n";
		cout << s << '\n';

		system("pause");
	}
	{
		cout << "\n\n\n\n-=-=-=-=-=-=-Creating String type of sequence-=-=-=-=-=-=-\n\n";

		Sequence<String> s(5);

		cout << "\n_______Sequance before adding: " << s;

		s.add(String("kpop"));
		s.add(String("rock"));
		s.add(String("soul"));
		s.add(String("jazz"));
		cout << "\n_______Sequance after adding: " << s << '\n';

		s.remove(0);
		cout << "\n_______Removed first 3 elements: " << s << '\n';

		s.insert(String("---"), 0);
		cout << s << '\n';

		cout << "\n_______element 5 is in the sequance?\n";
		cout << (s.contains(5) ? "Element 5 is in the sequance\n" : "Element 5 is not in the sequance\n");

		cout << "\n_______sequance is full?\n";
		cout << (s.full() ? "Sequence sequance is full\n" : "Sequence sequance is not full\n");

		cout << "\n_______Cut sequance:\n";
		s.cut();
		cout << s << '\n';

		s.clear();
		cout << "\n_______Clear sequance:\n";
		cout << s << '\n';

		system("pause");
	}

	return 0;
}


