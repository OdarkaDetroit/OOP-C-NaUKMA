#pragma once

// 01LAB. Реалізувати і протестувати тип даних Point.

#ifndef _POINT_H_

#define _POINT_H_



#include <iostream>

using namespace std;



//*******************************************

//Every point posesses its unique ID.

//In debug mode both constructor and destructor

//report the ID and the coordinates

//of a point created or resp. deleted

//Developed by Shmielova Daria
//on Visual Studio
//Version 16.8.4

//*******************************************


class Point

{

private:

    static int _freeID;

    const int _pointID;

    double _x;

    double _y;

public:

    Point(double x = 0, double y = 0);

    Point(const Point&);

    ~Point()
    {
        //delete[]_y;
        _y = 0; _x = 0;
        return;
    }

    Point& operator=(const Point& u);
    //{
    //    _x = u._x;
    //    _y = u._y;
    //    return *this;
    //}

    double& x() { return _x; }

    double& y() { return _y; }

    const double& x()const { return _x; }

    const double& y()const { return _y; }

    const int getID() const { return _pointID; }
    
    static int amount() { return _freeID; }

};

ostream& operator<<(ostream&, const Point&);

const Point operator+ (const Point& u, const Point& v);

Point& operator+=(Point&, const Point&);

bool operator==(const Point& u, const Point& v);

bool operator!=(const Point& u, const Point& v);

#endif