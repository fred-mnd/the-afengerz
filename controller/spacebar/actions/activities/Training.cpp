#ifndef TRAINING_CPP
#define TRAINING_CPP

#include "Training.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../../view/headers/trainingPage.h"
#include "../../../../model/map/Room.h"

TrainingAct::TrainingAct() : Activities(){
    message = "Press Space to start training";
    pos = {10, 10};
    room = RoomNS::getRoom(RoomNS::TRAINING_ROOM);
    duration[0] = 15;
    duration[1] = 45;
    duration[2] = 90;
}

bool TrainingAct::action(){
    TrainingPage::show();
}

int TrainingAct::start(int options){
    return XPList[options];
}

void TrainingAct::end(Hero* hero, int change){
    hero->setXP(change);
}

#endif