#ifndef SLEEP_CPP
#define SLEEP_CPP

#include "Sleep.h"
#include "../../../../view/headers/sleepPage.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../headers/gameController.h"

SleepAct::SleepAct(Room* bedroom) : Activities(){
    prompt = "Press Space to sleep";
    
    pos = {3, 2};
    room = bedroom;
    durations[0] = 20;
    durations[1] = 60;
    durations[2] = 180;
    status = "Sleeping";
}

bool SleepAct::action(){
    int elig = checkEligibility(GameController::getCurrHero());
    if(elig == 0){
        SleepPage::show();
        return true;
    }
    else if(elig == 1){
        fail = "You're not idle";
    }
    else if(elig == 2){
        fail = "Your health is currently full";
    }
    setFail();
    return false;
}

int SleepAct::start(int options){
    duration = durations[options];
    score = scores[duration];
    return HPList[options];
}

void SleepAct::end(Hero* hero, int change){
    hero->setHealth(change);
}

int SleepAct::checkEligibility(Hero* hero){
    if(hero->getAct()) return 1;
    if(hero->getHealth() >= hero->getMaxHealth()) return 2;

    return 0;
}

#endif