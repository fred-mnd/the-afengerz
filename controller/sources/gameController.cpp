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
        // currHero = HeroNS::getHero(HeroNS::HULK);
        RoomNS::changeBedroom();
    }

    std::array<std::array<char, 31>,15> getMap(Room* room){
        return room->getMap();
    }
}

#endif