#include <string>
#include <iostream>
#include "Fun.h"

using namespace std;

bool Date::defaultSet = false;

int main()
{
	try {
		Date first;
		Date second(29, 2, 2020);
		Date third(11, Date::apr, 1941);
		Date fourth(third);
		Date fifth(-2, 3, -200);
	}
	catch (Date::BadDate bad) { cout << "Catched: " << bad << '\n'; }

	{// testing operator<<
		try {
			Date first;
			Date second(29, 2, 2020);
			Date third(11, Date::apr, 1941);
			Date fourth(third);

			cout << "_____Testing operator<< \n\n";
			cout << first << '\n';
			cout << second << '\n';
			cout << third << '\n';
			cout << fourth << "\n\n";
		}
		catch (Date::BadDate bad1) { cout << "Catched: " << bad1 << '\n'; }
	}
	{// testing day()/month()/year()
		try {
			Date first;
			Date second(29, 2, 2020);
			Date third(11, Date::apr, 1941);
			Date fourth(third);

			cout << "_____Testing day() \n\n";
			cout << "first -> " << first.day() << '\n';
			cout << "second(29, 2, 2020) -> " << second.day() << '\n';
			cout << "third(11, Date::apr, 1941) -> " << third.day() << '\n';
			cout << "fourth(third) -> " << fourth.day() << "\n\n"; 
			cout << "_____Testing month() \n\n";
			cout << "first -> " << first.month() << '\n';
			cout << "second(29, 2, 2020) -> " << second.month() << '\n';
			cout << "third(11, Date::apr, 1941) -> " << third.month() << '\n';
			cout << "fourth(third) -> " << fourth.month() << "\n\n";
			cout << "_____Testing year() \n\n";
			cout << "first -> " << first.year() << '\n';
			cout << "second(29, 2, 2020) -> " << second.year() << '\n';
			cout << "third(11, Date::apr, 1941) -> " << third.year() << '\n';
			cout << "fourth(third) -> " << fourth.year() << "\n\n";
		}
		catch (Date::BadDate bad2) { cout << "Catched: " << bad2 << '\n'; }
	}
	{// testing setDay()/setMonth()/setYear() 
		try {
			Date first;
			Date second(29, 2, 2020);
			Date third(11, Date::apr, 1941);
			Date fourth(third);

			cout << "_____Testing setDay()\n\n";
			first.setDay(17);
			fourth.setDay(4);
			cout << "first -> " << first.day() << '\n';
			cout << "fourth -> " << fourth.day() << "\n\n";
			cout << "_____Testing setMonth()\n\n";
			first.setMonth(1);
			fourth.setMonth(12);
			cout << "first -> " << first.month() << '\n';
			cout << "fourth -> " << fourth.month() << "\n\n";
			cout << "_____Testing setYear()\n\n";
			first.setYear(1780);
			fourth.setYear(2077);
			cout << "first -> " << first.year() << '\n';
			cout << "fourth -> " << fourth.year() << "\n\n";
		}
		catch (Date::BadDate bad3) { cout << "Catched: " << bad3 << '\n'; }
	}
	{// testing increment/decrement
		try {
			Date first;
			Date second(29, 2, 2020);
			Date third(11, Date::apr, 1941);
			Date fourth(third);

			cout << "_________________++/--____________________\n\n";
			
			cout << "--first =>" << --first << '\n';
			cout << "first-- =>" << first-- << '\n';
			cout << "--second =>" << --second << '\n';
			cout << "second-- =>" << second-- << '\n\n';
			cout << "___________________________________________\n";
			cout << "++third =>" << ++third << '\n';
			cout << "third++ =>" << third++ << '\n';
			cout << "++fourth =>" << ++fourth << '\n';
			cout << "fourth++ =>" << fourth++ << '\n\n';
		}
		catch (Date::BadDate bad4) { cout << "Catched: " << bad4 << '\n'; }
	}
}