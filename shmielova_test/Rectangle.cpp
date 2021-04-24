#pragma once

#include "HRectangle.h"
#include "Segment.h"

///////////////////////////////////////////////////////// сетери для вершин прямокутника

Point& HRectangle::setB(const Point& p) { _point = Point(p.x(), p.y() - height());  return _point; }

Point& HRectangle::setC(const Point& p) { _point = Point(p.x() - width(), p.y() - height()); return _point; }

Point& HRectangle::setD(const Point& p) { _point = Point(p.x() - width(), p.y()); return _point; }

/////////////////////////////////////////////////////////  Оператори +, =, <

HRectangle HRectangle::operator+(const HRectangle& r)
{
    Point min_point = apexA();
    if (r.apexA().x() <= min_point.x() && r.apexA().y() <= min_point.y())
    {
        min_point = r.apexA();
    }

    Point max_point = apexC();
    if (r.apexC().x() >= max_point.x() && r.apexC().y() >= max_point.y())
    {
        max_point = r.apexC();
    }

    double height = abs(max_point.y() - min_point.y()),
           width = abs(max_point.x() - min_point.x());

    return HRectangle(height, width, min_point);
}


HRectangle& HRectangle::operator=(const HRectangle& h)
{
    _height = h._height;
     _width = h._width;
     _point = h._point;

    return *this;
}


bool HRectangle::operator<(const HRectangle& r)
{
    if (height() < r.height() && width() < r.width())
    {
        return true;
    }
    return false;
}

///////////////////////////////////////////////////////////// Оператор виведення

ostream& operator<<(ostream& os, const HRectangle& r)
{
    os << "Rectangle: \n_____________\n";
    os << "apex A: " << r.apexA();
    os << "\napex B: " << r.apexB();
    os << "\napex C: " << r.apexC();
    os << "\napex D: " << r.apexD();

    os << "\n_ _ _ _ _ _ _ _\nSides:\n_ _ _ _ _ _ _ _\n";
    os << r.side_ab() << '\n';
    os << r.side_bc() << '\n';
    os << r.side_cd() << '\n';
    os << r.side_da();

    os << "_ _ _ _ _ _ _ _\n>>Area: " << r.area() << "\n_ _ _ _ _ _ _ _\n";

    return os;
}

