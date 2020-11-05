/*
** EPITECH PROJECT, 2019
** pacman
** File description:
** Map.cpp
*/

#include "Map.hpp"
#define HUD_SIZE 12

Map::Map()
{
    std::ifstream myStream;
    std::string mapString;

    _sizeX = 0;
    _sizeX = 0;
    myStream.open("resources/map/map.txt");
    while(std::getline(myStream, mapString, '\n')) {
        _sizeY++;
        _map.push_back(mapString);
        if (mapString.size() > (size_t)_sizeX)
            _sizeX = mapString.size();
    }
}

std::vector<std::string>& Map::getMap()
{
    return _map;
}

std::vector<std::string> const& Map::getMap() const
{
    return _map;
};

void Map::printMap()
{
    for (size_t i = 0; i < _map.size(); i++) {
        for (size_t y = 0; _map[i].size() && _map[i][y]; y++) {
            if (_map[i][y] != ' ')
                attron(COLOR_PAIR(8));
            mvaddch(HUD_SIZE - 1 + i, y, _map[i][y]);
            if (_map[i][y] != ' ')
                attroff(COLOR_PAIR(8));
        }
    }
}

void Map::update()
{
    printMap();
}