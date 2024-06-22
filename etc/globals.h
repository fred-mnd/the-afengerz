#ifndef GLOBALS_H
#define GLOBALS_H

#include <windows.h>

namespace Globals{
    enum COLORS{
        RED = 31,
        BLUE = 34,
        GREEN = 32,
        PURPLE = 35,
        GRAY = 90,
        YELLOW = 33,
        WHITE = 37,
    };

    const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    const COORD UP_LEFT = {0, 0};
    const COORD ROOM_NAME = {35, 2};
    const COORD ACTION_MESSAGE = {35, 5};

    extern bool gameOver;
    
}

#endif