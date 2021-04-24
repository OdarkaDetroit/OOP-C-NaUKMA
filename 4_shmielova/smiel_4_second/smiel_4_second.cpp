// smiel_4_second.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Header_s.h"
#include "Header_t.h"
#include "Header_p.h"

using namespace std;

int main()
{
	{
		cout << "-=-=-=-=-=-=--=-=-=-=-=-=-\n\n";

		Triangle ABC(2, 0, 5, 5, 0, 5);

		cout << "___ABC(2, 0, 5, 5, 0, 5) --> " << ABC;
		cout << "\nPerimeter ABC: " << ABC.perimeter();
		cout << "\nArea ABC: " << ABC.area();
		cout << "\nHeight A: " << ABC.height_a();
		cout << "\nHeight B: " << ABC.height_b();
		cout << "\nHeight C: " << ABC.height_c();
	}

	{
		cout << "\n\n-=-=-=-=-=-=--=-=-=-=-=-=-\n\n";

		Point p1(0, 0), p2(8, 0), p3(0, 17);
		Triangle ABC(p1, p2, p3);

		cout << "|p1(0, 0), p2(8, 0), p3(0, 17)|___ABC(p1, p2, p3) --> " << ABC;
		cout << "\nPerimeter ABC: " << ABC.perimeter();
		cout << "\nArea ABC: " << ABC.area();
		cout << "\nHeight A: " << ABC.height_a(); 
		cout << "\nHeight B: " << ABC.height_b();
		cout << "\nHeight C: " << ABC.height_c();
	}

	{
		cout << "\n\n-=-=-=-=-=-=--=-=-=-=-=-=-\n\n";

		Point p1(0, 5), p2(14, 5), p3(0, 20);
		Triangle ABC(p1, p2, p3);
		Triangle copyABC(ABC);
		cout << "|p1(0, 5), p2(14, 5), p3(0, 20)|\n|ABC(p1, p2, p3)|\ncopyABC(ABC) --> " << copyABC;

		cout << "\ncopyABC Vertices: " << copyABC.apexA() << copyABC.apexB() << copyABC.apexC();

		cout << "\n___________________\nSide a: " << copyABC.side_a();
		cout << "\nSide b:" << copyABC.side_b();
		cout << "\nSide c:" << copyABC.side_c() << '\n';
	}

	return 0;
}

