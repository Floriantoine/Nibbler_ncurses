/*
** EPITECH PROJECT, 2019
** ncurses
** File description:
** Timer.hpp
*/

#pragma once
#include <chrono>

class Clock {
    using clocktype = std::chrono::high_resolution_clock;

  public:
    Clock() : startTime{clocktype::now()}
    {
    }
    Clock(Clock& toCopy) = delete;
    Clock(Clock&& toMove) = delete;

    ~Clock() = default;

    long getElapsedTime()
    {
        std::chrono::duration<double, std::milli> elapsed_time =
            clocktype::now() - this->startTime;

        return static_cast<long>(elapsed_time.count());
    }

    void reset()
    {
        this->startTime = clocktype::now();
    }

  private:
    std::chrono::time_point<clocktype> startTime;
};