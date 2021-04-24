// 8(1)_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Screen.h"

using namespace std;

int main()
{

	char filler[] = { "----------------------------" };
	const int demoLength = 4, demoWidth = 4;
	Screen scr(demoLength, demoWidth, filler);



	const NonConstAction menuNonConst[] = { &Screen::home, &Screen::move, &Screen::back, &Screen::clear, &Screen::show };
	const ConstAction menuConst[] = { &Screen::home, &Screen::move, &Screen::back, &Screen::show, &Screen::showCurrent };
	int k;
	int n;
	char ch;

	cout << "=-=-=-=-=- Menu Non Const =-=-=-=-=-\n\n";
	scr.show();
	do {
		do
		{
			cout << "____________________________________________\nChoose any option --> (0-home:1-move:2-back:3-clear:4-show:5-showCurrent:6-set)";
			cin >> k;
			if (k == 6)
			{
				cout << "Setting '.': \n";
				scr.set('.').move().set('.').show();
				cout << "\n\n";
			}
			cin.clear();
			cin.ignore(1000, '\n');
		} while ((k < 0) || (k > 6));

		do {
			cout << "-_-_-_-_-_-How many times repeat action? ";
			cin >> n;
			if (!isdigit(n))
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}
		} while (n<0 || n>demoLength * demoWidth);

		doActionNonConst(scr, menuNonConst[k], n);
		do {
			cout << "+-+-+-+-+-+One more time?(y/n) ";
			cin >> ch;
		} while (ch != 'y' && ch != 'n' && ch != 'Y' && ch != 'N');
	} while (ch == 'y' || ch == 'Y');
	scr.show();

	cout << "=-=-=-=-=- Menu Const =-=-=-=-=-\n\n";

	scr.show();
	do {

		do
		{
			cout << "_________________________________________\nChoose any option --> (0-home:1-move:2-back:3-show:4-showCurrent): ";
			cin >> k;
			cin.clear();
			cin.ignore(1000, '\n');
		} while ((k < 0) || (k > 4));

		do {
			cout << "-_-_-_-_-_-How many times repeat action? ";
			cin >> n;
			cin.clear();
			cin.ignore(1000, '\n');
		} while (n<0 || n>demoLength * demoWidth);

		doActionConst(scr, menuConst[k], n);
		do {
			cout << "+-+-+-+-+-+One more time?(y/n) ";
			cin >> ch;
		} while (ch != 'y' && ch != 'n' && ch != 'Y' && ch != 'N');

	} while (ch == 'y' || ch == 'Y');
	scr.show();


	system("pause");
	return 0;
}

