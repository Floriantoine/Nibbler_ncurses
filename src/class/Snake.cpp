/*
** EPITECH PROJECT, 2019
** snake
** File description:
** Snake.cpp
*/

#include "Snake.hpp"

int screenToMap(int pos)
{
    return (pos - (HUD_SIZE - 1));
}

int mapToScreen(int pos)
{
    return (pos + (HUD_SIZE + 1));
}

int Snake::getLife() const
{
    return _life;
}

void Snake::checkEntry(int entry, std::vector<std::string> map, body head)
{
    if (entry == 260 || entry == 261) {
        if (entry == 261 && _dirX != -1 &&
            map[screenToMap(head.y)][head.x + 1] == ' ')
            _dirX = 1;
        if (entry == 260 && _dirX != 1 &&
            map[screenToMap(head.y)][head.x - 1] == ' ')
            _dirX = -1;
        if (_dirX != 0)
            _dirY = 0;
    } else if (entry == 258 || entry == 259) {
        if (entry == 259 && _dirY != 1 &&
            map[screenToMap(head.y - 1)][head.x] == ' ')
            _dirY = -1;
        if (entry == 258 && _dirY != -1 &&
            map[screenToMap(head.y + 1)][head.x] == ' ')
            _dirY = 1;
        if (_dirY != 0)
            _dirX = 0;
    }
}

int Snake::moveSnake()
{
    if (_bodyChain.size() > (size_t)_size)
        _bodyChain.erase(_bodyChain.begin());
    if (_dirX != 0 || _dirY != 0)
        _bodyChain.push_back(body({_bodyChain[_bodyChain.size() - 1].x + _dirX,
            _bodyChain[_bodyChain.size() - 1].y + _dirY}));
    return (0);
}

void Snake::checkSelfColli(std::vector<std::string> map)
{
    body head = _bodyChain[_bodyChain.size() - 1];

    if (map[head.y - (HUD_SIZE - 1) + _dirY][head.x + _dirX] != ' ') {
        _dirX = 0;
        _dirY = 0;
    }
    // _life = 0;
    if (_bodyChain.size() < 5)
        return;
    for (size_t i = 0; i < _bodyChain.size() - 1; i++) {
        if (head.x == _bodyChain[i].x && head.y == _bodyChain[i].y) {
            _life--;
            return;
        }
    }
}

ObjType Snake::checkObjColli(body bodyInf, std::vector<ObjInf> &objVector)
{
    ObjType typeObjEat = ObjType::NONE;
    size_t i = 0;

    for (auto &elem: objVector) {
        if (elem.x == bodyInf.x && elem.y == bodyInf.y) {
            if (elem.type == ObjType::APPLE)
                _size += 4;
            else if (elem.type == ObjType::LIFE && _life < 3)
                _life++;
            typeObjEat = elem.type;
            objVector.erase(objVector.begin() + i);
            return typeObjEat;
        }
        ++i;
    }
    return typeObjEat;
}

ObjType Snake::Update(std::vector<int> eventKey, std::vector<ObjInf> &objVector,
    std::vector<std::string> map)
{
    body head = _bodyChain[_bodyChain.size() - 1];
    _windowX = getmaxx(stdscr);
    _windowY = getmaxy(stdscr);
    checkSelfColli(map);
    for (auto const &elem: eventKey)
        checkEntry(elem, map, head);
    for (auto const &elem: this->_bodyChain) {
        attron(COLOR_PAIR(3));
        mvaddch(elem.y, elem.x, 'O');
        attroff(COLOR_PAIR(3));
    }
    moveSnake();
    return checkObjColli(_bodyChain[_bodyChain.size() - 1], objVector);
}

void Snake::upSize(int x, int y)
{
    _size++;
    _bodyChain.push_back(body({x, y}));
}

Snake::Snake(std::vector<std::string> Map)
    : _windowX(getmaxx(stdscr)), _windowY(getmaxy(stdscr))
{
    (void)Map;
    _life = 1;
    _size = 3;
    _dirX = 1;
    _dirY = 0;
    upSize(65, mapToScreen(25));
    upSize(65, mapToScreen(25));
    upSize(65, mapToScreen(25));
    upSize(65, mapToScreen(25));
}

Snake::~Snake()
{
}
