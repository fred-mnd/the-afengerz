#ifndef SLEEP_H
#define SLEEP_H

#include "../Activities.h"
#include "../../../../view/headers/sleepPage.h"

class SleepAct : public Activities{
public:
    SleepAct() : Activities(){
        message = "Press Space to sleep";
    }

    void action(){
        SleepPage::show();
    }
};

#endif