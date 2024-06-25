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
    
    pos = {10, 10};
    room = RoomNS::getRoom(RoomNS::TRAINING_ROOM);
    durations[0] = 15;
    durations[1] = 45;
    durations[2] = 90;
    status = "Training";
}

bool TrainingAct::action(){
    int elig = checkEligibility(GameController::getCurrHero());
    if(elig == 0){
        TrainingPage::show();
        return true;
    }
    else if(elig == 1){
        fail = "You're not idle";
    }
    else if(elig == 2){
        fail = "Someone else is currently training";
    }
    setFail();
    return false;  
}

int TrainingAct::start(int options){
    duration = durations[options];
    score = scores[options];
    return XPList[options];
}

void TrainingAct::end(Hero* hero, int change){
    hero->setXP(change);
}

int TrainingAct::checkEligibility(Hero* hero){
    if(hero->getAct()) return 1;
    if(RoomNS::getRoom(RoomNS::TRAINING_ROOM)->getHeroList().size() != 0) return 2;

    return 0;
}

#endif