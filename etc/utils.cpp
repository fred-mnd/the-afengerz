#ifndef UTILS_CPP
#define UTILS_CPP

#include "globals.h"
#include "../model/heroes/Hero.h"
#include <string>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

namespace Utils{
    void changeCursorPos(COORD pos){
        SetConsoleCursorPosition(Globals::handle, pos);
    }

    void hideCursor(){
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(Globals::handle, &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(Globals::handle, &cursorInfo);
    }

    void showCursor(){
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(Globals::handle, &cursorInfo);
        cursorInfo.bVisible = true;
        SetConsoleCursorInfo(Globals::handle, &cursorInfo);
    }

    void cls(){
        system("cls");
    }

    char getKeyInput(){
        return tolower(getch());
    }

    void printHeroCoded(Hero* hero, std::string message){
        printf("\e[%dm%s\e[39m", hero->getColor(), message.c_str());
    }

    void printHeroCoded(Hero* hero, char character){
        printf("\e[%dm%c\e[39m", hero->getColor(), character);
    }

    void clearText(COORD coor){
        changeCursorPos(coor);
        printf("\e[K");
    }
}

#endif