#ifndef EAT_CPP
#define EAT_CPP

#include "Eat.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../../view/headers/eatPage.h"
#include "../../../headers/gameController.h"
#include "../../../../model/map/Room.h"

COORD EatAct::posList[4] = {{9, 4}, {19, 4}, {9, 9}, {19, 9}};
bool EatAct::roomOcc[4] = {false, false, false, false};

EatAct::EatAct() : Activities(){
    message = "Press Space to eat";
    room = RoomNS::getRoom(RoomNS::RESTAURANT);
    
    duration[0] = 10;
    duration[1] = 45;
    duration[2] = 90;
}

bool EatAct::action(){
    if(checkEligibility(GameController::getCurrHero())){
        EatPage::show();
        return true;
    }
    else{
        message = "Your hunger is currently full";
    }
    return false;
}

int EatAct::start(int options){
    for(int i=0;i<4;i++){
        if(!roomOcc[i]){
            posIdx = i;
            pos = posList[i];
            roomOcc[i] = true;
            return addHP[options];
        }
    }
    return addHP[options];
}

void EatAct::end(Hero* hero, int change){
    hero->setHunger(change);
}

bool EatAct::checkEligibility(Hero* hero){
    return hero->getHunger() < hero->getMaxHunger();
}

#endif