/*
** EPITECH PROJECT, 2019
** snake
** File description:
** snake.hpp
*/

#pragma once
#include <vector>
#include "Obj.hpp"
#include "ncurses.h"
#include <string>
#include "color.hpp"
#include "constants.hpp"

struct body
{
    int x;
    int y;
};

class Snake
{
private:
    int _windowX;
    int _windowY;
    int _size;
    int _dirX;
    int _dirY;
    int _life;
    std::vector<body> _bodyChain;
public:
    void checkSelfColli(std::vector<std::string> map);
    ObjType checkObjColli(body bodyInf, std::vector<ObjInf>& objVector);
    void checkEntry(int entry, std::vector<std::string> map, body head);
    ObjType Update(std::vector<int> eventKey, std::vector<ObjInf>& objVector, std::vector<std::string> map);
    void upSize(int x, int y);
    int moveSnake();
    int getLife() const;
    Snake(std::vector<std::string>);
    ~Snake();
};

int mapToScreen(int pos);
int screenToMap(int pos);