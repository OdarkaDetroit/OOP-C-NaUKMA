#include <iostream>
#include "Fun.h"


using namespace std;

int Point::_freeID = 0;

int main() 
{
	Point p1(2, 8), p2(10, 40), p3(50, 200);
	{
		cout << "p1( " << p1.x() << ", " << p1.y() << " ); freeID = " << p1.getID() << '\n';
		cout << "p2( " << p2.x() << ", " << p2.y() << " ); freeID = " << p2.getID() << '\n';
		cout << "p3( " << p3.x() << ", " << p3.y() << " ); freeID = " << p3.getID() << "\n\n";

		cout << "Points existing here: " << Point::amount() << "\n\n";
	}
	{
		cout << "|| Comparising ==/!= ||\n";

		cout << "( p2 == p3 ) = " << (p2 == p3) << '\n';
		cout << "( p2 != p3 ) = " << (p2 != p3) << "\n\n";
	}
	Point copy_of_p1(p1);
	{
		cout << "|| Copying ||\n";

		cout << "copy_of_p1( " << copy_of_p1.x() << ", " << copy_of_p1.y() << " ); freeID = " << copy_of_p1.getID() << "\n\n";
		cout << "( p1 == copy_of_p1 ) = " << (p1 == copy_of_p1) << "\n\n";
	}
	{
		cout << "|| Nadannia znachennia = ||" << '\n';

		cout << "( p1Copy == p2) = " << (copy_of_p1 == p2) << '\n';
		copy_of_p1 = p2;
		cout << "**copy_of_p1( " << copy_of_p1.x() << ", " << copy_of_p1.y() << " ); freeID = " << copy_of_p1.getID() << '\n';
		cout << "( p1Copy == p2 ) = " << (copy_of_p1 == p2) << "\n\n";
	}
	{
		cout << "|| Printing cout ||" << '\n';

		cout << p1 << '\n';
		cout << p2 << '\n';
		cout << p3 << "\n\n";
	}
	{
		cout << "|| Addition 1.0 + ||" << '\n';

		cout << "( p1 + p2 ) = " << (p1 + p2) << '\n';
		cout << "( p3 + p3 ) = " << (p1 + p1) << "\n\n";
	}
	{
		cout << "|| Addition 1.1 += ||" << '\n';

		cout << "( p2 += p3 ) = " << (p2 += p1) << "\n\n Deleted \n\n";
	}
	return 0;
}