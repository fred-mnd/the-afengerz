#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "../../model/heroes/Hero.h"
#include <array>

namespace GameController{
    Hero* getCurrHero();
    void init();

    std::array<std::array<char, 31>,15> getMap(Room* room);
}

#endif