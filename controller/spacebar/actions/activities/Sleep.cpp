#ifndef SLEEP_CPP
#define SLEEP_CPP

#include "Sleep.h"
#include "../../../../view/headers/sleepPage.h"
#include "../../../../model/heroes/Hero.h"

SleepAct::SleepAct(Room* bedroom) : Activities(){
    message = "Press Space to sleep";
    pos = {3, 2};
    room = bedroom;
}

void SleepAct::action(){
    SleepPage::show();
}

void SleepAct::start(int options){
    HP = HPList[options];
}

void SleepAct::end(Hero* hero){
    hero->setHealth(HP);
}

#endif