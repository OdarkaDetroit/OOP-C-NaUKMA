#pragma once

#include "Time.h"
#include "Date.h"

class Timer
{

private:

    Time _presetTime;
    Date _presetDate;
    void checkTheDate();


public:
    Timer(Time time, Date date);

    Timer(const Timer& timer);

    ~Timer();

    void start(const int seconds);
};