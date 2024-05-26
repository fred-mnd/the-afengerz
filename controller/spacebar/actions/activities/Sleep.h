#ifndef SLEEP_H
#define SLEEP_H

#include "../Activities.h"

class SleepAct : public Activities{
private:
    int HP;
    int HPList[3] = {15, 35, 100};
public:
    SleepAct(Room* bedroom);

    void action();

    void start(int options);

    void end(Hero* hero);

};

#endif