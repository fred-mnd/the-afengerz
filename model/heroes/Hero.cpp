#ifndef HERO_CPP
#define HERO_CPP

#include <vector>
#include <array>

#include "Hero.h"
#include "../../etc/globals.h"
#include "../../controller/spacebar/actions/activities/Sleep.h"
namespace HeroNS{
    std::array<Hero*, 6> heroes;

    Hero* getHero(int index){
        return heroes[index];
    }

    void init(){
        heroes[0] = new Hero("black-widow", 'B', Globals::WHITE);
        heroes[0]->getBedroom()->addFeatures({0,0}, {7,17}, new SleepAct());

        heroes[1] = new Hero("captain-america", 'C', Globals::BLUE);
        heroes[1]->getBedroom()->addFeatures({0,0}, {7,7}, new SleepAct());

        heroes[2] = new Hero("hawkeye", 'K', Globals::PURPLE);
        heroes[2]->getBedroom()->addFeatures({0,0}, {7,7}, new SleepAct());

        heroes[3] = new Hero("hulk", 'H', Globals::GREEN);
        heroes[3]->getBedroom()->addFeatures({0,0}, {12,10}, new SleepAct());

        heroes[4] = new Hero("iron-man", 'I', Globals::RED);
        heroes[4]->getBedroom()->addFeatures({0,0}, {7,7}, new SleepAct());

        heroes[5] = new Hero("thor", 'T', Globals::GRAY);
        heroes[5]->getBedroom()->addFeatures({0,0}, {7,7}, new SleepAct());
    }
}


#endif