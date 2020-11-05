/*
** EPITECH PROJECT, 2019
** snake
** File description:
** Snake.cpp
*/

#include "Setting.hpp"
#include "Body.hpp"
#include "ncurses.h"

void Setting::saveEvent(int event)
{
    if (event != -1)
        _eventKey.push_back(event);
}

int Setting::getSnakeLife()
{
    return _snake.getLife();
}

void Setting::setWindow(int x, int y)
{
    _windowX = x;
    _windowY = y;
}

void Setting::newObj(int x, int y, ObjType type)
{
    _objVector.push_back(ObjInf({x, y, type}));
}

void Setting::updateHUD()
{
    mvprintw(2, 1,
        "     /\\\\\\\\\\\\\\\\\\\\\\    /\\\\\\\\\\     /\\\\\\     "
        "/\\\\\\\\\\\\\\\\\\     /\\\\\\        /\\\\\\  "
        "/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\                /^\\/^\\");
    mvprintw(3, 1,
        "    /\\\\\\/////////\\\\\\ \\/\\\\\\\\\\\\   \\/\\\\\\   "
        "/\\\\\\\\\\\\\\\\\\\\\\\\\\  \\/\\\\\\     /\\\\\\//  "
        "\\/\\\\\\///////////              _|__|  O|");
    mvprintw(4, 1,
        "    \\//\\\\\\      \\///  \\/\\\\\\/\\\\\\  \\/\\\\\\  "
        "/\\\\\\/////////\\\\\\ \\/\\\\\\  /\\\\\\//     \\/\\\\\\             "
        "  \\/     /~     \\_/ \\");
    mvprintw(5, 1,
        "      \\////\\\\\\         \\/\\\\\\//\\\\\\ \\/\\\\\\ \\/\\\\\\      "
        " \\/\\\\\\ \\/\\\\\\\\\\\\//\\\\\\     \\/\\\\\\\\\\\\\\\\\\\\\\      "
        "  \\____|__________/  \\");
    mvprintw(6, 1,
        "          \\////\\\\\\      \\/\\\\\\\\//\\\\\\\\/\\\\\\ "
        "\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\/\\\\\\//  //\\\\\\     "
        "/\\\\\\///////               \\_______      \\");
    mvprintw(7, 1,
        "              \\////\\\\\\   \\/\\\\\\ \\//\\\\\\/\\\\\\ "
        "\\/\\\\\\/////////\\\\\\ \\/\\\\\\     //\\\\\\   \\/\\\\\\           "
        "                  `\\     \\                 \\");
    mvprintw(8, 1,
        "        /\\\\\\      \\//\\\\\\  \\/\\\\\\  \\//\\\\\\\\\\\\ "
        "\\/\\\\\\       \\/\\\\\\ \\/\\\\\\     \\//\\\\\\  \\/\\\\\\         "
        "                     |     |                  \\");
    mvprintw(9, 1,
        "        \\///\\\\\\\\\\\\\\\\\\\\\\/   \\/\\\\\\   \\//\\\\\\\\\\ "
        "\\/\\\\\\       \\/\\\\\\ \\/\\\\\\      \\//\\\\\\  "
        "/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\                /      /               "
        "     \\");
    mvprintw(10, 1,
        "           \\///////////     \\///     \\/////  \\///        \\///  "
        "\\///        \\///  \\///////////////               /     /           "
        "            \\\\");

    for (int i = 0; i < 3; i++) {
        if (i < _snake.getLife())
            attron(COLOR_PAIR(1));
        mvprintw(1, _windowX - i * 6 - 6, " _  _");
        mvprintw(2, _windowX - i * 6 - 6, "( `' )");
        mvprintw(3, _windowX - i * 6 - 6, " `.,'");
        if (i < _snake.getLife())
            attroff(COLOR_PAIR(1));
    }
    mvprintw(HUD_SIZE - 2, _windowX - 50, "TIME:    ");
    mvprintw(HUD_SIZE - 2, _windowX - 45, std::to_string(120 - _timer.getElapsedTime() / 1000).c_str());
    mvprintw(HUD_SIZE - 2, _windowX - 35, "APPLE:   | LIFE:  ");
    attron(COLOR_PAIR(RED_BLACK));
    mvaddch(HUD_SIZE - 2, _windowX - 28, 'O');
    attroff(COLOR_PAIR(RED_BLACK));
    attron(COLOR_PAIR(CYAN_BLACK));
    mvaddch(HUD_SIZE - 2, _windowX - 17, 'L');
    attroff(COLOR_PAIR(CYAN_BLACK));
}

int Setting::Update()
{
    std::vector<std::string>& map = _map.getMap();
    int mapSizeX = map[0].size();
    int mapSizeY = map.size();

    _map.update();
    wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');
    updateHUD();
    _windowX = getmaxx(stdscr);
    _windowY = getmaxy(stdscr);
    ObjType objEat = _snake.Update(_eventKey, _objVector, _map.getMap());
    if (objEat != ObjType::NONE)
        _objVector.push_back(
            randyObjinf({HUD_OFFSET, HUD_SIZE + HUD_OFFSET, objEat},
                {mapSizeX - HUD_OFFSET, mapSizeY - HUD_OFFSET, objEat}, map));
    for (auto const &elem: _objVector) {
        if (elem.type == ObjType::APPLE) {
            attron(COLOR_PAIR(RED_BLACK));
            mvaddch(elem.y, elem.x, 'O');
            attroff(COLOR_PAIR(RED_BLACK));
        } else if (elem.type == ObjType::LIFE) {
            attron(COLOR_PAIR(CYAN_BLACK));
            mvaddch(elem.y, elem.x, 'L');
            attroff(COLOR_PAIR(CYAN_BLACK));
        }
    }
    _eventKey.clear();
    refresh();
    return 0;
}

void Setting::initGame()
{
    _timer.reset();
}

int Setting::getRemainingTime()
{
    return 120 - _timer.getElapsedTime() / 1000;
}

Setting::Setting()
    : _windowX(getmaxx(stdscr)), _windowY(getmaxy(stdscr)), _map(),
      _snake(_map.getMap())
{
    std::vector<std::string> map = _map.getMap();
    int mapSizeX = map[0].size();
    int mapSizeY = map.size();

    for (size_t i = 0; i < 15; i++) {
        _objVector.push_back(
            randyObjinf({HUD_OFFSET, HUD_SIZE + HUD_OFFSET, APPLE},
                {mapSizeX - HUD_OFFSET, mapSizeY - HUD_OFFSET, APPLE}, map));
    }
    _objVector.push_back(randyObjinf({HUD_OFFSET, HUD_SIZE + HUD_OFFSET, LIFE},
        {mapSizeX - HUD_OFFSET, mapSizeY - HUD_OFFSET, LIFE}, map));
}

Setting::~Setting()
{
}
