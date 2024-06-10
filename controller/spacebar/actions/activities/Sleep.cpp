#ifndef SLEEP_CPP
#define SLEEP_CPP

#include "Sleep.h"
#include "../../../../view/headers/sleepPage.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../headers/gameController.h"

SleepAct::SleepAct(Room* bedroom) : Activities(){
    message = "Press Space to sleep";
    pos = {3, 2};
    room = bedroom;
    duration[0] = 20;
    duration[1] = 60;
    duration[2] = 180;
}

bool SleepAct::action(){
    if(checkEligibility(GameController::getCurrHero())){
        SleepPage::show();
        return true;
    }
    else{
        message = "Your health is currently full";
    }
    return false;
}

void SleepAct::start(int options){
    HP = HPList[options];
}

void SleepAct::end(Hero* hero){
    hero->setHealth(HP);
}

bool SleepAct::checkEligibility(Hero* hero){
    return hero->getHealth() < hero->getMaxHealth();
}

#endif