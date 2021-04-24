// shmielova_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#include "HRectangle.h"
#include "HSquare.h"
#include "Point.h"
#include "Container.h"


int main()
{
    HRectangle r1(1, 2, Point(0, 0));
    HRectangle r2(1, 2, Point(-1, -2));
    HRectangle r3(-1, -2, Point(0, 0));
    HRectangle r4(-1, -2, Point(1, 2));
    HRectangle r5(-1, -2, Point(-1, -2));

    HSquare s1(2, Point(0, 0));
    HSquare s2(2, Point(-1, -2));
    HSquare s3(2, Point(1, 2));
    HSquare s4(-2, Point(0, 0));
    HSquare s5(-2, Point(1, 2));
    HSquare s6(-2, Point(-1, -2));

  {// TESTING HRectangle
      cout << "-+-+-+-+-+-+-+-+- Rectangle observation -+-+-+-+-+-+-+-+-\n\n";

      cout << "_____\n| r1 |   (1, 2, Point(0, 0))\n_____\n"<< r1 << "\n____________________________\n";
      cout << "_____\n| r2 |   (1, 2, Point(-1, -2))\n_____\n"<< r2 << "\n____________________________\n";
      cout << "_____\n| r3 |   (-1, -2, Point(0, 0))\n_____\n"<< r3 << "\n____________________________\n";
      cout << "_____\n| r4 |   (-1, -2, Point(1, 2))\n_____\n"<< r4 << "\n____________________________\n";
      cout << "_____\n| r5 |   (-1, -2, Point(-1, -2))\n_____\n"<< r5 << "\n____________________________\n";

      {//methods of HRectangle testing
          cout << "***Testing methods for r1:\n";
          cout << "-- height() --> " << r1.height();
          cout << "\n-- width() --> " << r1.width();
          cout << "\n-- area() --> " << r1.area();
          cout << "\n_ _ _ _ _ _ _ _ _ _";
          cout << "\n-- side_ab() --> " << r1.side_ab();
          cout << "\n-- side_bc() --> " << r1.side_bc();
          cout << "\n-- side_cd() --> " << r1.side_cd();
          cout << "\n-- side_da() --> " << r1.side_da();
          cout << "\n_ _ _ _ _ _ _ _ _ _";
          cout << "\n-- apexA() --> " << r1.apexA();
          cout << "\n-- apexB() --> " << r1.apexB();
          cout << "\n-- apexC() --> " << r1.apexC();
          cout << "\n-- apexD() --> " << r1.apexD();
      }
      {
          cout << "r1(1, 2, Point(0, 0)) < r2(1, 2, Point(-1, -2))  ::> " << (r1 < r2);
          cout << "\nr2(1, 2, Point(-1, -2)) < r1(1, 2, Point(0, 0))  ::> " << (r2 < r1);
      }
      {
          cout << "\n\n>>>>>>>>Setters:\n\n";
          cout << "r3 (A) before --> " << r3.apexA();
          r3.setA(Point(-1, -1));
          cout << "\nr3 (A) after --> " << r3.apexA() << "-" << r3.apexB() << "-" << r3.apexC() << "-" << r3.apexD();

          cout << "\n\nr3 (B) before --> " << r3.apexB();
          r3.setB(Point(-3, -5));
          cout << "\nr3 (B) after --> " << r3.apexA() << "-" << r3.apexB() << "-" << r3.apexC() << "-" << r3.apexD();

          cout << "\n\nr3 (C) before --> " << r3.apexC();
          r3.setC(Point(3, 5));
          cout << "\nr3 (C) after --> " << r3.apexA() << "-" << r3.apexB() << "-" << r3.apexC() << "-" << r3.apexD();

          cout << "\n\nr3 (D) before --> " << r3.apexD();
          r3.setD(Point(1, 1));
          cout << "\nr3 (D) after --> " << r3.apexA() << "-" << r3.apexB() << "-" << r3.apexC() << "-" << r3.apexD();
      }

      cout << "\n___________________________\n(r1 = (r1 + r2)) --> " << (r1 = (r1 + r2)) << '\n';
      cout << "\n___________________________\n(r1 + r3)) --> " << (r1 + r3) << '\n';
  }
  {
      cout << "\n\n-+-+-+-+-+-+-+-+- Square observation -+-+-+-+-+-+-+-+-\n\n";

      {
          cout << "_____\n| s1 |   (2, Point(0, 0))\n_____\n" << s1 << "\n____________________________\n";
          cout << "_____\n| s2 |   (2, Point(-1, -2))\n_____\n" << s2 << "\n____________________________\n";
          cout << "_____\n| s3 |   (2, Point(1, 2))\n_____\n" << s3 << "\n____________________________\n";
          cout << "_____\n| s4 |   (-2, Point(0, 0))\n_____\n" << s4 << "\n____________________________\n";
          cout << "_____\n| s5 |   (-2, Point(1, 2))\n_____\n" << s5 << "\n____________________________\n";
          cout << "_____\n| s6 |   (-2, Point(-1, -2))\n_____\n" << s6 << "\n____________________________\n";
      }

      {//methods of HSquare testing
          cout << "***Testing methods for r1:\n";
          cout << "-- height() --> " << s1.height();
          cout << "\n-- width() --> " << s1.width();
          cout << "\n-- area() --> " << s1.area();
          cout << "\n_ _ _ _ _ _ _ _ _ _";
          cout << "\n-- side_ab() --> " << s1.side_ab();
          cout << "\n-- side_bc() --> " << s1.side_bc();
          cout << "\n-- side_cd() --> " << s1.side_cd();
          cout << "\n-- side_da() --> " << s1.side_da();
          cout << "\n_ _ _ _ _ _ _ _ _ _";
          cout << "\n-- apexA() --> " << s1.apexA();
          cout << "\n-- apexB() --> " << s1.apexB();
          cout << "\n-- apexC() --> " << s1.apexC();
          cout << "\n-- apexD() --> " << s1.apexD();
      }
      {
          cout << "\n\n>>>>>>>>Setters:\n\n";
          cout << "s3 (A) before --> " << s3.apexA();
          s3.setA(Point(-1, -1));
          cout << "\ns3 (A) after --> " << s3.apexA() << "-" << s3.apexB() << "-" << s3.apexC() << "-" << s3.apexD();

          cout << "\n\ns3 (B) before --> " << s3.apexB();
          s3.setB(Point(-3, -5));
          cout << "\ns3 (B) after --> " << s3.apexA() << "-" << s3.apexB() << "-" << s3.apexC() << "-" << s3.apexD();

          cout << "\n\ns3 (C) before --> " << s3.apexC();
          s3.setC(Point(3, 5));
          cout << "\ns3 (C) after --> " << s3.apexA() << "-" << s3.apexB() << "-" << s3.apexC() << "-" << s3.apexD();

          cout << "\n\ns3 (D) before --> " << s3.apexD();
          s3.setD(Point(1, 1));
          cout << "\ns3 (D) after --> " << s3.apexA() << "-" << s3.apexB() << "-" << s3.apexC() << "-" << s3.apexD();
      }
      {
          cout << "s1(2, Point(0, 0)) < s3)  ::> " << (s1 < s2);
          cout << "\ns3 < s1(2, Point(0, 0))  ::> " << (s2 < s1);
      }
      {
          cout << "(s1 = (s1 + s3))" << (s1 = (s1 + s3)) << '\n';

          HSquare s11(7, Point(0, 0));
          cout << s11;

          HSquare s22(10, Point(-2, -2));
          cout << s22;

          cout << "____________\n(s1 = (s1 + s3)) --> " << (s1 + s3) << '\n';

          cout << "**********copying: \n";
          HRectangle r_1(1, 2, Point(0, 0));
          cout << "HRectangler_1(1, 2, Point(0, 0)) --> HSquare --> " << HSquare(r_1);
      }
  }
  {
      cout << "\n\n-+-+-+-+-+-+-+-+- Rectangle observation with Container -+-+-+-+-+-+-+-+-\n\n";

      Container<HRectangle> c1(5);

      c1.add(r1);
      c1.add(r2);
      c1.add(r3);
      c1.add(r4);
      c1.add(r5);

      Container<HRectangle> c2(c1.lessThan(r1));

      cout << "\n__________----------________\n" << c2 << '\n';
  }
  {
      cout << "\n\n-+-+-+-+-+-+-+-+- Square observation with Container -+-+-+-+-+-+-+-+-\n\n";

      Container<HSquare> c(6);

      c.add(s1);
      c.add(s2);
      c.add(s3);
      c.add(s4);
      c.add(s5);
      c.add(s6);

      Container<HSquare> c2(c.lessThan(s1));
      cout << "\n__________----------________\n" << c2 << '\n';

      HSquare res(c.toUnion());
      cout << "-- toUnion --> "<< res;
  }
    return 0;
}

