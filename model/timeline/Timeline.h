#ifndef TIMELINE_H
#define TIMELINE_H

#include <time.h>
#include <stdlib.h>
#include "../heroes/Hero.h"

struct TimeNode{
    clock_t endTime;
    Hero* hero;
    TimeNode* next;
};

class Timeline{
private:
    TimeNode *head, *tail;

    TimeNode* createNode(clock_t endTime, Hero* hero);

public:
    Timeline();

    void pushMid(clock_t endTime, Hero* hero);

    Hero* popHead();

    void view();

    clock_t getHeadTime();

    bool isHead();
};

#endif