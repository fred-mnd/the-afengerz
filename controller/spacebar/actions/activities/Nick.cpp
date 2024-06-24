#ifndef NICK_CPP
#define NICK_CPP

#include "Nick.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../../model/timeline/Timeline.h"
#include "../../../../model/map/Room.h"
#include "../../../../view/headers/gamePage.h"
#include "../../../headers/gameController.h"
#include <stdlib.h>

NickAct::NickAct(){
    pos = {12, 6};
    room = new Room("battlefield", "Battlefield");
    duration = 200;
    status = "On Duty";
}

bool NickAct::action(){

}

int NickAct::start(int options){
    return -10;
}

void NickAct::end(Hero* hero, int change){
    srand(time(0));
    int decrease = rand() % 21 + 40; // 40-60
    int coverPercent = rand() % 21 + 30; // 30-50

    int cover = decrease * coverPercent / 100;
    int eq = hero->getEqHealth() > cover ? cover : eq;
    int health = decrease - cover;
    int hunger = rand() % 31 + 30; // 30-60

    hero->setHealth(health);
    hero->setHunger(hunger);
    hero->decreaseEquipmentHealth(eq);

    hero->setAct(NULL);
    if(GameController::getCurrHero() == hero){
        GamePage::refreshUI();
    }
}

int NickAct::checkEligibility(Hero* hero){
    if((hero->getAct() && hero->getAct()->change == 0) || room->getHeroList().size() >= 1) return 1;
    return 0;
}


#endif