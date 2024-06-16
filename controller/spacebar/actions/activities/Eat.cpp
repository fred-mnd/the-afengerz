#ifndef EAT_CPP
#define EAT_CPP

#include "Eat.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../../view/headers/eatPage.h"
#include "../../../headers/gameController.h"
#include "../../../../model/map/Room.h"
#include <vector>

COORD EatAct::posList[4] = {{9, 4}, {19, 4}, {9, 9}, {19, 9}};
bool EatAct::roomOcc[4] = {false, false, false, false};

EatAct::EatAct() : Activities(){
    prompt = "Press Space to eat";
    fail = "Your hunger is currently full";
    room = RoomNS::getRoom(RoomNS::RESTAURANT);
    
    durations[0] = 10;
    durations[1] = 45;
    durations[2] = 90;
}

bool EatAct::action(){
    if(checkEligibility(GameController::getCurrHero())){
        EatPage::show();
        return true;
    }
    else{
        setFail();
    }
    return false;
}

int EatAct::start(int options){
    for(int i=0;i<4;i++){
        if(!roomOcc[i]){
            posIdx = i;
            pos = posList[i];
            roomOcc[i] = true;
            break;
        }
    }
    duration = durations[options];
    return addHP[options];
}

void EatAct::end(Hero* hero, int change){
    hero->setHunger(change);
}

bool EatAct::checkEligibility(Hero* hero){
    return !hero->getAct() && hero->getHunger() < hero->getMaxHunger() && RoomNS::getRoom(RoomNS::RESTAURANT)->getHeroList().size() < 4;
}

#endif