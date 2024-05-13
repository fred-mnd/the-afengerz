#ifndef UTILS_CPP
#define UTILS_CPP

#include "globals.h"
#include <windows.h>

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
}

#endif