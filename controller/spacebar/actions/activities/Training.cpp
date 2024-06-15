#ifndef TRAINING_CPP
#define TRAINING_CPP

#include "Training.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../../view/headers/trainingPage.h"
#include "../../../../model/map/Room.h"
#include "../../../../model/timeline/Timeline.h"
#include "../../../headers/gameController.h"
#include <vector>

TrainingAct::TrainingAct() : Activities(){
    prompt = "Press Space to start training";
    fail = "Someone else is curently training";
    pos = {10, 10};
    room = RoomNS::getRoom(RoomNS::TRAINING_ROOM);
    durations[0] = 15;
    durations[1] = 45;
    durations[2] = 90;
}

bool TrainingAct::action(){
    if(checkEligibility(GameController::getCurrHero())){
        TrainingPage::show();
        return true;
    }
    else{
        message = "Your health is currently full";
    }
    return false;    
}

int TrainingAct::start(int options){
    duration = durations[options];
    return XPList[options];
}

void TrainingAct::end(Hero* hero, int change){
    hero->setXP(change);
}

bool TrainingAct::checkEligibility(Hero* hero){
    return !hero->getAct() && RoomNS::getRoom(RoomNS::TRAINING_ROOM)->getHeroList().size() == 0;
}

#endif