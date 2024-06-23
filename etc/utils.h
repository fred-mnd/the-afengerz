#ifndef UTILS_H
#define UTILS_H

class Hero;

#include <windows.h>
#include <string>

namespace Utils{
    void changeCursorPos(COORD pos);
    void hideCursor();
    void showCursor();
    void cls();
    char getKeyInput();
    void printHeroCoded(Hero* hero, std::string message);
    void printHeroCoded(Hero* hero, char character);
    void clearText(COORD coor);
    std::string printTime(int minute);
    bool threadSleep(int sec);
}

#endif