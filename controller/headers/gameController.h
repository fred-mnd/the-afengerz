#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "../../model/heroes/Hero.h"
#include "../spacebar/SpaceBar.h"
#include <array>
#include <thread>

namespace GameController{
    Hero* getCurrHero();
    void setCurrHero(Hero* hero);
    void init();

    std::array<std::array<char, 31>,15> getCurrMap();
    void moveHero(COORD newPos);
    std::thread *getTimelineThread();
    std::thread *getSupThread();
    std::thread *getNickThread();
    void changeBedroom();
    bool changeHero();
    int getScore();
    int addScore(int add);
    
}

#endif