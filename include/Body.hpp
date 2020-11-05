#ifndef BODY_H
#define BODY_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

int body(Setting *setting);
int randy(int min, int max, int nop);
ObjInf randyObjinf(ObjInf min, ObjInf max, std::vector<std::string> const map);
#endif