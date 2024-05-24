#ifndef UTILS_H
#define UTILS_H

#include <windows.h>
#include <string>
#include "../model/heroes/Hero.h"

namespace Utils{
    void changeCursorPos(COORD pos);
    void hideCursor();
    void showCursor();
    void cls();
    char getKeyInput();
    void printHeroCoded(Hero* hero, std::string message);
    void printHeroCoded(Hero* hero, char character);
    void clearText(COORD coor);
}

#endif