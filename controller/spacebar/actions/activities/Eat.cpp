#ifndef EAT_CPP
#define EAT_CPP

#include "Eat.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../../view/headers/eatPage.h"
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

void EatAct::action(){
    EatPage::show();
}

void EatAct::start(int options){
    for(int i=0;i<4;i++){
        if(!roomOcc[i]){
            posIdx = i;
            pos = posList[i];
            roomOcc[i] = true;
            return;
        }
    }
    HP = addHP[options];
}

void EatAct::end(Hero* hero){
    hero->setHealth(HP);
}

#endif