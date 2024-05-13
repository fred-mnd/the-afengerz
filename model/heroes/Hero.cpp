#ifndef HERO_CPP
#define HERO_CPP

#include <vector>
#include <array>

#include "Hero.h"
#include "../../etc/globals.h"
namespace HeroNS{
    std::array<Hero*, 6> heroes;

    Hero* getHero(int index){
        return heroes[index];
    }

    void init(){
        heroes[0] = new Hero("black-widow", 'B', Globals::WHITE);
        heroes[1] = new Hero("captain-america", 'C', Globals::BLUE);
        heroes[2] = new Hero("hawkeye", 'K', Globals::PURPLE);
        heroes[3] = new Hero("hulk", 'H', Globals::GREEN);
        heroes[4] = new Hero("iron-man", 'I', Globals::RED);
        heroes[5] = new Hero("thor", 'T', Globals::GRAY);
    }
}


#endif