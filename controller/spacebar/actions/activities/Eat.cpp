#ifndef EAT_CPP
#define EAT_CPP

#include "Eat.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../../view/headers/eatPage.h"
#include "../../../headers/gameController.h"
#include "../../../../model/map/Room.h"
#include "../../../../model/timeline/Timeline.h"
#include <vector>

COORD EatAct::posList[4] = {{9, 4}, {20, 4}, {9, 10}, {20, 10}};
bool EatAct::roomOcc[4] = {false, false, false, false};

EatAct::EatAct() : Activities(){
    prompt = "Press Space to eat";
    room = RoomNS::getRoom(RoomNS::RESTAURANT);
    
    durations[0] = 10;
    durations[1] = 45;
    durations[2] = 90;
    status = "Eating";
}

bool EatAct::action(){
    int elig = checkEligibility(GameController::getCurrHero());
    if(elig == 0){
        EatPage::show();
        return true;
    }
    else if(elig == 1){
        fail = "You're not idle";
    }
    else if(elig == 2){
        fail = "Your hunger is currently full";
    }
    else if(elig == 3){
        fail = "The restaurant is full";
    }
    setFail();
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
    score = scores[options];
    return addHP[options];
}

void EatAct::end(Hero* hero, int change){
    hero->setHunger(change);
    forceRemove(hero);
}

void EatAct::forceRemove(Hero* hero){
    COORD pos = hero->getAct()->pos;
    for(int i=0;i<4;i++){
        COORD check = posList[i];
        if(check.X == pos.X && check.Y && pos.Y){
            roomOcc[i] = false;
            return;
        }
    }
}

int EatAct::checkEligibility(Hero* hero){
    if(hero->getAct()){
        return 1;
    }
    if(hero->getHunger() >= hero->getMaxHunger()){
        return 2;
    }
    if(RoomNS::getRoom(RoomNS::RESTAURANT)->getHeroList().size() >= 4){
        return 3;
    }

    return 0;
}

#endif