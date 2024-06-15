#ifndef SLEEP_CPP
#define SLEEP_CPP

#include "Sleep.h"
#include "../../../../view/headers/sleepPage.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../headers/gameController.h"

SleepAct::SleepAct(Room* bedroom) : Activities(){
    prompt = "Press Space to sleep";
    fail = "Your health is currently full";
    pos = {3, 2};
    room = bedroom;
    durations[0] = 20;
    durations[1] = 60;
    durations[2] = 180;
}

bool SleepAct::action(){
    if(checkEligibility(GameController::getCurrHero())){
        SleepPage::show();
        return true;
    }
    else{
        setFail();
    }
    return false;
}

int SleepAct::start(int options){
    duration = durations[options];
    return HPList[options];
}

void SleepAct::end(Hero* hero, int change){
    hero->setHealth(change);
}

bool SleepAct::checkEligibility(Hero* hero){
    return !hero->getAct() && hero->getHealth() < hero->getMaxHealth();
}

#endif