#ifndef SLEEP_H
#define SLEEP_H

#include "../Activities.h"

class SleepAct : public Activities{
public:
    SleepAct(Hero* currHero) : Activities(currHero){
        message = "sleep";
    }
};

#endif