/*
** EPITECH PROJECT, 2019
** pacman
** File description:
** Map.hpp
*/

#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "ncurses.h"

class Map
{
private:
    int _sizeX;
    int _sizeY;
    std::vector<std::string> _map;
public:
    Map();
    ~Map() = default;

    void update();
    void printMap();
    std::vector<std::string> const& getMap() const;
    std::vector<std::string>& getMap();
    char getChar(int x, int y) { return _map[y][x]; };
    void setChar(int x, int y, char entry) { _map[y][x] = entry; };
    void setSizeX(int newSizeX){ _sizeX = newSizeX; };
    void setSizeY(int newSizeY){ _sizeY = newSizeY; };
    int getSizeX() const { return _sizeX; };
    int getSizeY() const { return _sizeY; };
};