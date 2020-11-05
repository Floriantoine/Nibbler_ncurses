/*
** EPITECH PROJECT, 2019
** snake
** File description:
** Setting.hpp
*/

#pragma once
#include "Snake.hpp"
#include <ncurses.h>
#include "Obj.hpp"
#include "Map.hpp"
#include "Timer.hpp"

class Setting
{
private:
    Clock _timer;
    int _windowX;
    int _windowY;
    Map _map;
    Snake _snake;
    std::vector<int> _eventKey;
    std::vector<ObjInf> _objVector;
public:
    void updateHUD();
    void newObj(int x, int y, ObjType enumObj);
    void saveEvent(int event);
    int getSnakeLife();
    void setWindow(int x, int y);
    int Update();
    void initGame();
    int getRemainingTime();
    Setting();
    ~Setting();
};