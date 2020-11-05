/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main for Dante solver
*/

#include <curses.h>
#include <iostream>
#include "Setting.hpp"
#include "Body.hpp"
#include "color.hpp"
#include <ctime>

int init()
{
    initscr();
    start_color();
    if (has_colors() == FALSE)
    {
        std::cerr << "Your terminal does not support color\n" << std::endl;
        endwin();
        return (1);
    }
    noecho();
    curs_set(FALSE);
    keypad(stdscr, true);
    nodelay(stdscr, true);

    init_pair(MAGENTA_BLACK, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(BLUE_BLACK, COLOR_BLUE, COLOR_BLACK);
    init_pair(RED_BLACK, COLOR_RED, COLOR_BLACK);
    init_pair(YELLOW_BLACK, COLOR_YELLOW, COLOR_BLACK);
    init_pair(GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
    init_pair(CYAN_BLACK, COLOR_CYAN, COLOR_BLACK);
    init_pair(BLACK_BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(WHITE_WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(MAGENTA_MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(BLUE_BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(RED_RED, COLOR_RED, COLOR_RED);
    init_pair(YELLOW_YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(GREEN_GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(CYAN_CYAN, COLOR_CYAN, COLOR_CYAN);
    init_pair(BLACK_BLUE, COLOR_BLACK, COLOR_BLUE);
    init_pair(BLACK_RED, COLOR_BLACK, COLOR_RED);
    return (0);
}

int main(void)
{
    std::srand(std::time(NULL));

    if (init())
        return (84);

    Setting setting;
    if (body(&setting)) {
        endwin();
        return (84);
    }
    endwin();
    return (0);
}