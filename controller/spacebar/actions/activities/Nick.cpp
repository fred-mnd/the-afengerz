#ifndef NICK_CPP
#define NICK_CPP

#include "Nick.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../../model/timeline/Timeline.h"
#include "../../../../model/map/Room.h"
#include "../../../../view/headers/gamePage.h"
#include "../../../../etc/globals.h"
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
    score = 200;
    return -10;
}

void NickAct::end(Hero* hero, int change){
    srand(time(0));
    int decreaseHealth = rand() % 21 + 60; // 60-80
    int coverPercent = rand() % 21 + 30; // 30-50
    int cover = decreaseHealth * coverPercent / 100;

    int decreaseEquipment = cover;
    int remainingCover = 0;

    if (hero->getEqHealth() <= cover) {
        remainingCover = cover - hero->getEqHealth();
        decreaseEquipment = hero->getEqHealth();
    }
    decreaseHealth -= decreaseEquipment;
    decreaseHealth -= remainingCover;

    int decreaseHunger = rand() % 31 + 30; // 30-60
    int remainingHungerDecrease = 0;

    if (hero->getHunger() <= decreaseHunger) {
        remainingHungerDecrease = decreaseHunger - hero->getHunger();
        decreaseHunger = hero->getHunger();
    }
    decreaseHealth += remainingHungerDecrease;

    hero->decreaseEquipmentHealth(decreaseEquipment);
    hero->setHunger(-decreaseHunger);
    hero->setHealth(-decreaseHealth);

    if(hero->getHealth() <= 0){
        Globals::gameOver = true;
        return;
    }
    
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