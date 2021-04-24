#include <iostream>

using namespace std;

/*******************************************

//Every segment posesses its unique ID.

//In debug mode both constructor and destructor

//report the ID and the coordinates

//of a segment created or resp. deleted

//Developed by Daria Shmielova

//at Visual Studio

//Version 2019

*******************************************/

// клас точок

class Point

{

private:

    static int _freeID;

    const int _pointID;

    double _x;

    double _y;

public:

    Point(double x = 0, double y = 0) : _x(x), _y(y), _pointID(++_freeID) { return; }

    Point(const Point& u) : _x(u._x), _y(u._y), _pointID(++_freeID) { return; }

    ~Point()
    {
        _y = 0; _x = 0;
        return;
    }

    Point& operator=(const Point& u) 
    {
        _x = u._x;
        _y = u._y; 
        return *this; 
    }

    double& x() { return _x; }

    double& y() { return _y; }

    const double& x()const { return _x; }

    const double& y()const { return _y; }

    const int getID() const { return _pointID; }

    static int amount() { return _freeID; }

};

// Клас відрізків

class Segment

{

private:

    // Засоби облікування відрізків

    static int _freeID;
    const int _myId;

    Point _a;    // Точка початку відрізку
    Point _b;     // Точка кінця відрізку

public:

    // Конструктори відрізків

    
    // 1) за координатами його кінців
    Segment(const double x1 = 0, const double y1 = 0,
        const double x2 = 1, const double y2 = 0);

    // 2) за точками початку і кінця
    Segment(const Point& start, const Point& end);

    Segment(const Segment& seg);  // 3) копіювальний конструктор

    ~Segment();             // Деструктор

    Segment& operator=(const Segment&);    // Присвоєння

    // Селектори  точок

    const Point& start() const;

    const Point& end() const;

    // Селектори-модифікатори точок

    Point& start();

    Point& end();

    // Селектори координат точок

    const double& startX() const;

    const double& startY() const;

    const double& endX() const;

    const double& endY() const;

    // Селектори-модифікатори координат точок

    double& startX();
    double& startY();

    double& endX();
    double& endY();

    // Обчислення довжини відрізка
    double length() const;

    // Обчислення відстані від відрізка до точки

    double distance(Point& u) const;

    // Селектор ID

    const int getID() const;

};

ostream& operator<<(ostream&, const Segment&);

//for Point

const Point operator+ (const Point& u, const Point& v);

Point& operator+=(Point&, const Point&);

const Point operator- (const Point& u, const Point& v);

const Point operator* (const Point& u, const Point& v);
