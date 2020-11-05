
#include "Setting.hpp"
#include "Body.hpp"
#include <stdio.h>

int body(Setting *setting)
{
    while (setting->getSnakeLife() && setting->getRemainingTime() > 0) {
        setting->saveEvent(getch());
        setting->Update();
        // check_snake(param);
        usleep(90000 - (4 * 200));
    }
    return (0);
}
