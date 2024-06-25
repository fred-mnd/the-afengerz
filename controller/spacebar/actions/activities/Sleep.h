#ifndef SLEEP_H
#define SLEEP_H

#include "../Activities.h"

class SleepAct : public Activities{
private:
    int HPList[3] = {15, 35, 100};
    int scores[3] = {20, 30, 50};
public:
    SleepAct(Room* bedroom);

    bool action();

    int start(int options);

    void end(Hero* hero, int change);

    int checkEligibility(Hero* hero);

};

#endif