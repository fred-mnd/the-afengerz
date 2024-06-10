#ifndef MEETING_CPP
#define MEETING_CPP

#include "Meeting.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../headers/gameController.h"
#include "../../../../view/headers/upgradePage.h"
#include "../../../../model/map/Room.h"

MeetingAct::MeetingAct() : Activities(){
    message = "Press Space to repair equipment";
    duration[0] = 60;
    room = RoomNS::getRoom(RoomNS::MEETING_ROOM);
    pos = {10, 10};
}

bool MeetingAct::action(){
    if(checkEligibility(GameController::getCurrHero())){
        UpgradePage::show();
        return true;
    }
    else{
        message = "Not all heroes are idle.";
    }
    return false;
}

void MeetingAct::start(int options){
    
}

void MeetingAct::end(Hero* hero){
    hero->resetEquipmentHealth();
}

bool MeetingAct::checkEligibility(Hero* hero){
    for(int i=0;i<6;i++){
        if(HeroNS::getHero(i)->getAct()){
            return false;
        }
    }
    return true;
}

#endif