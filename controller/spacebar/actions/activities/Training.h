#ifndef TRAINING_H
#define TRAINING_H

#include "../Activities.h"
#include "../../../../view/headers/trainingPage.h"
#include "../../../../model/map/Room.h"

class TrainingAct : public Activities{
private:
    int XP;
    int XPList[3] = {20, 35, 50};
public:
    TrainingAct() : Activities(){
        message = "Press Space to start training";
        pos = {10, 8};
        room = RoomNS::getRoom(RoomNS::TRAINING_ROOM);
    }

    void action(){
        TrainingPage::show();
    }

    void start(int options){
        XP = XPList[options];
    }

    void end(Hero* hero){
        hero->setXP(XP);
    }
};

#endif