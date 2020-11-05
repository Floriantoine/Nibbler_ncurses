/*
** EPITECH PROJECT, 2019
** ncurses
** File description:
** Obj.hpp
*/

#pragma once

enum ObjType
{
    NONE = 0,
    APPLE = 1,
    LIFE = 2
};

struct ObjInf
{
    int x;
    int y;
    ObjType type;
};