// shmi_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>

#include"AComplex.h"
#include"TComplex.h"

using namespace std;
int main()
{
	AComplex a1;
	AComplex a2(10, -5.5), a3(0, 7.7);
	AComplex a4(a2);

	TComplex t1;
	TComplex t2(4.8, 60), t3(-1, 45), t5(474, 20);
	TComplex t4(t2);

	{ // using TComplex

	    cout << "\nComplex numbers in algebraic form\n\n";
		cout << "- - - - - - - - - - - - - - - - - - - -\n";
	   
	    a1.re() = 3;
	    a1.im() = 9;
	    cout << "\n-=-=-=-=>> a1.re = 3; a1.im = 9\n";
	    cout << a1.getID() << ": " << a1 << "\n";
	    cout << "-=-=-=-=>> a2.re = " << a2.re() << "; a2.im = " << a2.im() << "\n";
	    cout << "-=-=-=-=>> a3.conj = " << a3.conj() << "\n";
	    a3 = a1;
	    cout << "-=-=-=-=>> a3 = a1" << "\n";
	    cout << "-=-=-=-=>> reassigned a3: " << a3 << "\n";
	    cout << "-=-=-=-=>> a4.mod = " << a4.mod() << "\n";
	    cout << "-=-=-=-=>> a4.arg = " << a4.arg() << "\n";
	    
	    AComplex a5 = a1 + a2 + a3;
	    cout << "-=-=-=-=>> a1: " << a1 << "\n";
	    cout << "-=-=-=-=>> a5: " << a5 << "\n";
	    a5 += a1;
	    cout << "-=-=-=-=>> a5 += a1\nres: " << a5 << "\n";
	    a5 - a2;
	    cout << "-=-=-=-=>> a2: " << a2 << "\n";
	    cout << "-=-=-=-=>> a3: " << a3 << "\n";
	    cout << "-=-=-=-=>> a5: " << a5 << "\n";
	    a2 -= a3 -= a5;
	    cout << "-=-=-=-=>> a2 -=a3 -=a5\nres: " << a2 << "\n";
	    cout << "-=-=-=-=>> a1 == a5: " << (a1 == a5) << "\n";
	    cout << "-=-=-=-=>> a2 == a2: " << (a2 == a2) << "\n";
	    cout << "-=-=-=-=>> a1 != a2: " << (a1 != a2)  << "\n";
	    cout << "-=-=-=-=>> a4 != a4: " << (a4 != a4)  << "\n";

		cout << "\n________________________\nADDED: /=   AND    *=\n\n";
		a2 *= a2;
		cout << "a2 *= a2 ==> " << a2;
		a3 /= a2;
		cout << "\na3 /= a2 ==> " << a3;
 // }
	{ // using TComplex
		cout << "\n\nComplex numbers in trigonometric form\n\n";
		cout << "- - - - - - - - - - - - - - - - - - - -\n";

		t5 = t1;
		cout << "-=-=-=-=>> reassigned t5 (= t1): " << t5 << "\n";
		t5.mod() = 91;
		t5.arg() = 30;
		cout << "-=-=-=-=>> t5.mod = 91; t5.arg = 30" << "\n";
		cout << t5.getID() << ": " << t5;
		cout << "-=-=-=-=>> t4.mod = " << t4.mod() << "; t4.arg = " << t4.arg() << "\n";
		cout << "-=-=-=-=>> t3.re = " << t3.re() << "; t3.im = " << t3.im() << "\n";

		t2* t3;
		t2 / t3 / t5;
		cout << "-=-=-=-=>> t2: " << t2;
		cout << "-=-=-=-=>> t4: " << t4;
		cout << "-=-=-=-=>> t5: " << t5 << "\n";
		t2 *= t4 * t5;
		cout << "-=-=-=-=>> t2 *= t4 * t5\nres: " << t2 << "\n";
		cout << "-=-=-=-=>> t3: " << t3 << "\n";
		cout << "-=-=-=-=>> t5: " << t5 << "\n";
		t5 /= t3;
		cout << "-=-=-=-=>> t5 /= t3\nres: " << t5 << "\n";
		t4.mod() = 5.33;
		t4.arg() = 77;
		cout << "-=-=-=-=>> t4.mod = 5.33; t4.arg = 77" << "\n";
		t1.mod() = -2;
		t1.arg() = 90;
		cout << "-=-=-=-=>> t1.mod = -2; t1.arg = 90" << "\n";
		cout << "-=-=-=-=>> t1: " << t1 << "\n";
		cout << "-=-=-=-=>> t2: " << t2 << "\n";
		cout << "-=-=-=-=>> t3: " << t3 << "\n";
		cout << "-=-=-=-=>> t4: " << t4 << "\n";
		cout << "-=-=-=-=>> t5: " << t5 << "\n";
		t4 *= ((t5 /= t2) * t3) / t1;
		cout << "-=-=-=-=>> t4 *= ((t5 /= t2) * t3) /  t1\nres: " << t4 << "\n";


		cout << "\n________________________\nADDED: -=   AND    +=\n\n";
		t1 += t2;
		cout << "-=-=-=-=>> t1 += t2 ==> " << t1;
		t2 -= t4;
		cout << "\n-=-=-=-=>> t2 -= t4 ==> " << t2;
	}
	{ 
		cout << "\n\noperations with both types of complex numbers\n\n";
		cout << "- - - - - - - - - - - - - - - - - - - - - - - -\n";

		cout << "-=-=-=-=>> 1000 + t1: " << 1000 + t1;
		cout << "\n-=-=-=-=>> t4 + t1: " << t4 + t1;
		cout << "\n-=-=-=-=>> t5 - t4: " << t5 - t4;
		cout << "\n-=-=-=-=>> a2 - t3: " << a2 - t4;
		cout << "\n-=-=-=-=>> t4 * 1000: " << t4 * 1000;
		cout << "\n-=-=-=-=>> a1 * a2: " << a1 * a2;
		cout << "\n-=-=-=-=>> a2 / a1: " << a2 / a1;
		cout << "\n-=-=-=-=>> a1 / t1: " << a1 / t1;
		cout << "\n-=-=-=-=>> a2 += (a1 * t3 - a3)\nres: " << (a2 += (a1 * t3 - a3)) << "\n";
		cout << "-=-=-=-=>> AComplex(t3): " << AComplex(t3) << "\n";
		cout << "-=-=-=-=>> TComplex(a4)==a4: " << (TComplex(a4) == a4) << "\n";
		cout << "-=-=-=-=>> t2 == t2: " << (t2 == t2) << "\n";
		cout << "-=-=-=-=>> t5 == t1: " << (t5 == t1) << "\n";
		cout << "-=-=-=-=>> t4 != t3: " << (t4 != t3) << "\n";
		cout << "-=-=-=-=>> t5 != t5: " << (t5 != t5) << "\n";
	}


	return 0;
}