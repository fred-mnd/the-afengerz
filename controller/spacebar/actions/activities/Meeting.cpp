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
    duration = 60;
    room = RoomNS::getRoom(RoomNS::MEETING_ROOM);
    status = "Meeting";
}

bool MeetingAct::action(){
    int elig = checkEligibility(GameController::getCurrHero());
    if(elig == 0){
        MeetingPage::show();
        return true;
    }
    else{
        fail = "Not all heroas are idle";
    }
    setFail();
    return false;
}

int MeetingAct::start(int options){
    pos = poses[options];
    score = 20;
    return 0;
}

void MeetingAct::end(Hero* hero, int change){
    if(hero->getXP() == hero->getMaxXP()){
        hero->levelUp();
        GameController::addScore(80);
    }
}

int MeetingAct::checkEligibility(Hero* hero){
    for(int i=0;i<6;i++){
        if(HeroNS::getHero(i)->getAct()){
            return 1;
        }
    }
    return 0;
}

#endif