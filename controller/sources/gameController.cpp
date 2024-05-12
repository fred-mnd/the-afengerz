#ifndef GAME_CONTROLLER_CPP
#define GAME_CONTROLLER_CPP

#include "../../model/heroes/Hero.h"
#include <iostream>
#include <cstdlib>

namespace GameController{

    Hero* currHero;

    Hero* getCurrHero(){
        return currHero;
    }

    void init(){
        RoomNS::init();
        HeroNS::init();
        currHero = HeroNS::getHero(std::rand() % 6);
        RoomNS::changeBedroom();
    }
}

#endif