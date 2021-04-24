#pragma once

#include "HTetragon.h"


class HParallelogram : virtual public HTetragon
{

public:
    // конструктори
    HParallelogram(const double h, const double w, const double a, const Point p) 
        : HTetragon(h, w, a, p) 
    {

    };

    HParallelogram() {}
    // деструктор
    ~HParallelogram() 
    {

    }
};
