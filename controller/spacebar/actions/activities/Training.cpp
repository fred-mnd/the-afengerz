#ifndef TRAINING_CPP
#define TRAINING_CPP

#include "Training.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../../view/headers/trainingPage.h"
#include "../../../../model/map/Room.h"

TrainingAct::TrainingAct() : Activities(){
    message = "Press Space to start training";
    pos = {10, 8};
    room = RoomNS::getRoom(RoomNS::TRAINING_ROOM);
}

void TrainingAct::action(){
    TrainingPage::show();
}

void TrainingAct::start(int options){
    XP = XPList[options];
}

void TrainingAct::end(Hero* hero){
    hero->setXP(XP);
}

#endif