#ifndef SLEEP_H
#define SLEEP_H

#include "../Activities.h"
#include "../../../../view/headers/sleepPage.h"

class SleepAct : public Activities{
private:
    int HP;
    int HPList[3] = {15, 35, 100};
public:
    SleepAct() : Activities(){
        message = "Press Space to sleep";
        pos = {3, 2};
    }

    void action(){
        SleepPage::show();
    }

    void start(int options){
        HP = HPList[options];
    }

    void end(Hero* hero){
        hero->setHealth(HP);
    }
};

#endif