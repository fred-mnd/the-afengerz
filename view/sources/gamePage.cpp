#ifndef GAME_PAGE_CPP
#define GAME_PAGE_CPP

#include <array>
#include "../../controller/headers/gameController.h"

namespace GamePage{
    void printRoom(){
        std::array<std::array<char, 31>, 15> map = GameController::getMap(GameController::getCurrHero()->getCurrRoom());
        for(int i=0;i<15;i++){
            printf("%s\n", map[i]);
        }
    }
}

#endif