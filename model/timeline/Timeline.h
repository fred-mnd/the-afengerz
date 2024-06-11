#ifndef TIMELINE_H
#define TIMELINE_H

#include <time.h>
#include <stdlib.h>
#include "../heroes/Hero.h"

class Activities;

struct TimeNode{
    clock_t endTime;
    Hero* hero;
    Activities* act;
    TimeNode* next, *prev;
    COORD pos;
    int change;
};

class Timeline{
private:
    TimeNode *head, *tail;

    TimeNode* createNode(clock_t endTime, Hero* hero, Activities* act);

public:
    Timeline();

    TimeNode* pushMid(clock_t endTime, Hero* hero, Activities* act);

    Activities* popHead();

    void view();

    clock_t getHeadTime();

    bool isHead();
};

#endif