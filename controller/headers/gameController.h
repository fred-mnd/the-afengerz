#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "../../model/heroes/Hero.h"
#include "../../model/spacebar/SpaceBar.h"
#include <array>

namespace GameController{
    Hero* getCurrHero();
    void init();

    std::array<std::array<char, 31>,15> getCurrMap();
    COORD getHeroPos(Hero* hero);
    void getHeroPrintFormat(Hero* hero, std::string& print);
    void moveHero(short x, short y);
}

#endif