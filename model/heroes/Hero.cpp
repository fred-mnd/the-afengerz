#ifndef HERO_CPP
#define HERO_CPP

#include <vector>
#include "Hero.h"
#include <array>

namespace HeroNS{
    std::array<Hero*, 6> heroes;

    Hero* getHero(int index){
        return heroes[index];
    }

    void init(){
        heroes[0] = new Hero("black-widow");
        heroes[1] = new Hero("captain-america");
        heroes[2] = new Hero("hawkeye");
        heroes[3] = new Hero("hulk");
        heroes[4] = new Hero("iron-man");
        heroes[5] = new Hero("thor");
    }
}


#endif