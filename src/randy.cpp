/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** randy.c
*/

#include <ctime>
#include <stdlib.h>
#include <stdio.h>

#include "Obj.hpp"
#include "Setting.hpp"

int randy(int min, int max, int nop)
{
    int out_rand = nop;
    max += 1;

    while (out_rand < min || out_rand >= max || out_rand == nop)
    {
        out_rand = std::rand() % (max - min) + min;
    }
    return (out_rand);
}


ObjInf randyObjinf(ObjInf min, ObjInf max, std::vector<std::string> const map)
{
    ObjInf output;
    int x = randy(min.x, max.x, -1);
    int y = randy(min.y, max.y, -1);

    for (size_t i = 0; i < 10; i++)
    {
        while (map[screenToMap(y)][x] != ' ')
        {
            x = randy(min.x, max.x, -1);
            y = randy(min.y, max.y, -1);
        }
    }
    output.x = x;
    output.y = y;
    output.type = min.type;
    return output;
}
