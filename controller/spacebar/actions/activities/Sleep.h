#ifndef SLEEP_H
#define SLEEP_H

#include "../Activities.h"

class SleepAct : public Activities{
private:
    int HPList[3] = {15, 35, 100};
public:
    SleepAct(Room* bedroom);

    bool action();

    int start(int options);

    void end(Hero* hero, int change);

    bool checkEligibility(Hero* hero);

};

#endif