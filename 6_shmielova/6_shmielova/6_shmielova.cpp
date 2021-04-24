// 6_shmielova.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Date.h"
#include "Time.h"
#include "Timer.h"
#include "Watcher.h"

bool Date::defaultSet = 0;
//Date::Date defaultDay;

int main()
{
	cout << "_________________\nCreate my time \n\n";

	Time t1;               //by default
	Time t2(13, 28, 51);   //by definig data
	Time t3(t2);           //by copying
	Time t4;               //by default

    {//TESTING constructors work
    	cout << "_________________\nHow it looks like \n\n";
    
    	cout << "t1 = " << t1 << '\n';
    	cout << "t2(13, 28, 51) = " << t2 << '\n';
    	cout << "t3(t2) = " << t2 << " -> " << t3 << '\n';
    	cout << "Before operator= --> " << t4 << " and  " << t3 << '\n';
    
    	t4 = t3;
    	cout << "Aafter operator= --> " << t4 << " == " << t3 << '\n';
    }
    {//TESTING selectors and modifiers
    	cout << "_________________\nget and set\n\n";
    	cout << "t4 = " << t4 << '\n';
    	t4.hour() = 20;
    	t4.minute() = 20;
    	t4.second() = 20;
    	cout << "after --> " << t4 << '\n';
    }
    {// TESTING toint && todouble 
        cout << "_________________\ndouble --> int and vise wersa\n\n";
    	cout << "t3 (" << t3 << ") to int (seconds) -->" << int(t3) << '\n';
    	cout << "t2 (" << t2 << ") to double (hours) -->" << double(t2) << '\n';
    }
    {// TESTING operators
        cout << "_________________\n+ and -";
    	cout << "Time " << t4 << " to double " << double(t4) << " + Time " << t3 << " to double " << double(t3) << " = " << t4 + t3 << '\n';
    
    	cout << "_________________\n++ and --\n\n";
    
    	cout << "t3++\n";
    	cout << "before " << t3++ << '\n';
    	cout << "after: " << t3 << "\n\n";
    
    	cout << "++t3 \n";
    	cout << "before " << t3 << '\n';
    	cout << "after: " << ++t3 << "\n\n";
    
    	cout << "t3-- \n";
    	cout << "before " << t3-- << '\n';
    	cout << "after: " << t3 << "\n\n";
    
    	cout << "--t3 \n";
    	cout << "before " << t3 << '\n';
    	cout << "after: " << --t3 << '\n';
    }
    {// TESTING timer
    	cout << "_________________\nTesting timer\n\n";

    	Date today(t1);
    	Time stopAt(0, 0, 5);
    
    	Timer my_timer(stopAt, today);
    	my_timer.start(5);

    }

    {// TESTING watcher
        try
        {

            cout << "_________________\nTesting watch\n\n";

            Date today(7, 3, 2021);
            Time stopAt(23, 21, 0);
            Watcher w1(today, stopAt);


            cout << w1;

            w1.begin();
        }
        catch (const char*)
        {

        }
    }

	return 0;
}

