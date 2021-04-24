// 2_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Fun.h"

int Segment::_freeID = 0;
int Point::_freeID = 0;

int main()
{
	// 1) за координатами його кінців
	Segment seg0,
		    seg1(2, 8, 4, 16),
		    seg2(50, 200, 100, 400);

	// 2) за точками початку і кінця
	Point p1(10, -40), p2(-20, 80);
	Segment seg3(p1, p2);

	// 3) копіювальний конструктор
	Segment copy_of_seg1(seg1);

	{// Testing operator<<
		cout << "seg0: (<- id = " << seg0.getID() << ")\n" << seg0; 
		cout << "seg1: (<- id = " << seg1.getID() << ")\n" << seg1; 
		cout << "seg2: (<- id = " << seg2.getID() << ")\n" << seg2;
		cout << "seg3: (<- id = " << seg3.getID() << ")\n" << seg3;
		cout << "copy_of_seg1: (<- id = " << copy_of_seg1.getID() << ")\n" << copy_of_seg1 << "\n\n";
	}
	{// Testing operator=
		cout << "|| Prysvojennia = ||\n";
		copy_of_seg1 = seg3;
		cout << "after ~copy_of_seg1 = seg3~ \n";
		cout << "**\ncopy_of_seg1: (<- id = " << copy_of_seg1.getID() << ")\n" << copy_of_seg1 << "**\n\n";
	}
	{// Testing methods startX()/startY()/endX()/endY() 
		cout << "|| Every coordinate in separate ||\n";
		cout << "the a-point X of seg1: " << seg1.startX() << '\n';
		cout << "the a-point Y of seg1: " << seg1.startY() << '\n';
		cout << "the b-point X of seg1: " << seg1.endX() << '\n';
		cout << "the b-point Y of seg1: " << seg1.endY() << '\n';
		//now after Prysvojennia
		seg1.startX() = -2;
		seg1.startY() = -8;
		seg1.endX() = -4;
		seg1.endY() = -16;
		cout << "after using operator=\n";
		cout << "the a-point X of seg1: " << seg1.startX() << '\n';
		cout << "the a-point Y of seg1: " << seg1.startY() << '\n';
		cout << "the b-point X of seg1: " << seg1.endX() << '\n';
		cout << "the b-point Y of seg1: " << seg1.endY() << "\n\n";
	}
	{// Testing method length()
		cout << "|| length() method ||\n";
		cout << "length of seg0: " << seg0.length() << '\n';
		cout << "length of seg1: " << seg1.length() << '\n';
		cout << "length of seg2: " << seg2.length() << '\n';
		cout << "length of seg3: " << seg3.length() << "\n\n";
	}
	{// Testing method distance()
		cout << "|| distance() method ||\n";
		cout << seg0.distance(p1) << '\n';
		cout << seg3.distance(p2) << '\n';
		cout << seg2.distance(p1) << '\n';
		cout << "\n\n";
	}
	return 0;
}
