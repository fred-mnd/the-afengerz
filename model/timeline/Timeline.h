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

struct MasterTime{
    TimeNode *head, *tail;
    MasterTime *prev, *next;
};

class Timeline{
private:
    MasterTime *head, *tail;

    TimeNode* createNode(clock_t endTime, Hero* hero, Activities* act);
    MasterTime* createNode();

public:
    Timeline();

    TimeNode* pushMid(clock_t endTime, Hero* hero, Activities* act);

    Activities* popHead();

    void cleanUp();

    clock_t getHeadTime();

    bool isHead();

    bool isEmpty();

    void popMid(TimeNode* tn);
};

#endif