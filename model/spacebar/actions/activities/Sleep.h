#ifndef SLEEP_H
#define SLEEP_H

#include "../Activities.h"

class SleepAct : public Activities{
public:
    SleepAct() : Activities(){
        message = "sleep";
    }
};

#endif