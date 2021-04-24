#define _CRT_SECURE_NO_WARNINGS

#include "Timer.h"
#include "Time.h"

#include <thread>    
#include <chrono>     

#pragma warning(disable : 4996)


void Timer::checkTheDate()
{

    time_t current_td = time(0); // time && date now

    struct tm tm;

    localtime_s(&tm, &current_td);

    Time ct = Time(tm.tm_sec, tm.tm_min, tm.tm_hour);                // current time
    Date today = Date(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900); // current date

    while (today.day() != _presetDate.day())
    {
        cout << "wait a day while timer will work";
        std::this_thread::sleep_for(std::chrono::hours(24));
    }

    int now = int(ct);
    int setTime = int(_presetTime);

    for (int i = now; i <= setTime; ++i)
    {
        cout << "wait a second more while timer will wake up";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

Timer::Timer(Time time, Date date) : _presetDate(date), _presetTime(time) { checkTheDate(); cout << "Timer created!\n"; }

Timer::Timer(const Timer& timer) : _presetDate(timer._presetDate), _presetTime(timer._presetTime) { checkTheDate(); cout << "Timer created!\n"; }

Timer::~Timer() { cout << "Timer deleted!\n"; }

void Timer::start(const int seconds)
{
    int j = 0;
    for (int i = int(_presetTime); i <= (int(_presetTime) + seconds); ++i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << j << " sec gone...\n";
        ++j;
    }

    cout << "Time has ended up!\n\n" << endl;
}