#ifndef MEETING_CPP
#define MEETING_CPP

#include "Meeting.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../headers/gameController.h"
#include "../../../../view/headers/meetingPage.h"
#include "../../../../model/map/Room.h"

COORD MeetingAct::poses[6] = {{10, 4}, {10, 8}, {14, 8}, {14, 4}, {18, 4}, {18, 8}};

MeetingAct::MeetingAct() : Activities(){
    prompt = "Press Space to initiate meeting";
    fail = "Not all heroas are idle";
    duration = 10;
    room = RoomNS::getRoom(RoomNS::MEETING_ROOM);
}

bool MeetingAct::action(){
    if(checkEligibility(GameController::getCurrHero())){
        MeetingPage::show();
        return true;
    }
    else{
        setFail();
    }
    return false;
}

int MeetingAct::start(int options){
    pos = poses[options];
    return 0;
}

void MeetingAct::end(Hero* hero, int change){
    if(hero->getXP() == hero->getMaxXP()){
        hero->levelUp();
    }
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