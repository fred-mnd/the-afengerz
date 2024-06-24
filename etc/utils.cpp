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

    std::string printTime(int minute){
        int hours = minute / 60;
        int mins = minute % 60;

        std::string text;

        if(hours > 0) text += std::to_string(hours) + " hour(s) ";
        if(mins > 0){
            text += std::to_string(mins) + " minute(s)";
        }

        return text;
    }

    void clearText(COORD coor){
        changeCursorPos(coor);
        printf("\e[K");
    }

    void clearBlock(COORD coor){
        changeCursorPos(coor);
        printf("\e[J");
    }

    bool threadSleep(int sec){
        for(int i=0;i<sec;i++){
            if(Globals::gameOver == true){
                return false;
            }
            Sleep(1000);
        }
        return true;
    }
}

#endif