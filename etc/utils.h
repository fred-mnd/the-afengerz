#ifndef UTILS_H
#define UTILS_H

#include <windows.h>

namespace Utils{
    void changeCursorPos(COORD pos);
    void hideCursor();
    void showCursor();
    void cls();
}

#endif