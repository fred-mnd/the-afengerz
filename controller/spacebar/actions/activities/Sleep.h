#ifndef SLEEP_H
#define SLEEP_H

#include "../Activities.h"
#include "../../../../view/headers/sleepPage.h"

class SleepAct : public Activities{
public:
    SleepAct() : Activities(){
        message = "Press Space to sleep";
        pos = {3, 2};
    }

    void action(){
        SleepPage::show();
    }

    void end(){
        printf("aughhhhhhhh");
    }
};

#endif