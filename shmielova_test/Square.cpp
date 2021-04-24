#include "HSquare.h"

///////////////////////////////////////  ???????????? ???????????

HSquare::HSquare(HRectangle& r) :
    HRectangle(r.width() > r.height() ? r.width() : r.height(),
        r.width() > r.height() ? r.width() : r.height(),
        r.apexA()),
    HTetragon(r.width() > r.height() ? r.width() : r.height(),
        r.width() > r.height() ? r.width() : r.height(),
        pi, r.apexA()) {}

/////////////////////////////////////////////////////  ????????? +

HSquare HSquare::operator+(const HSquare& r)
{
    double minX = apexA().x();
    double minY = apexA().y();

    if (r.apexA().x() <= minX) { minX = r.apexA().x(); }
    if (r.apexA().y() <= minY) { minY = r.apexA().y(); }

    double maxX = apexC().x();
    double maxY = apexC().y();

    if (r.apexC().x() >= maxX) { maxX = r.apexC().x(); }

    if (r.apexC().y() >= maxY) { maxY = r.apexC().y(); }

    Point first(minX, minY);
    Point second(maxX, maxY);

    double height = abs(first.y() - second.y());
    double width = abs(first.x() - second.x());

    if (height < width) { height = width; }

    return HSquare(height, first);
}

///////////////////////////////////////////////////// ???????? ?????????

ostream& operator<<(ostream& os, const HSquare& s)
{
    os << "Square: \n_____________\n";
    os << "apex A: " << s.apexA();
    os << "\napex B: " << s.apexB();
    os << "\napex C: " << s.apexC();
    os << "\napex D: " << s.apexD();

    os << "\n_ _ _ _ _ _ _ _\nSides:\n_ _ _ _ _ _ _ _\n";
    os << s.side_ab() << '\n';
    os << s.side_bc() << '\n';
    os << s.side_cd() << '\n';
    os << s.side_da();

    os << "_ _ _ _ _ _ _ _\n>>Area: " << s.area() << "\n_ _ _ _ _ _ _ _\n";

    return os;
}

