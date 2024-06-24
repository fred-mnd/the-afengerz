#ifndef TIMELINE_CONTROLLER_H
#define TIMELINE_CONTROLLER_H

#include "../../model/heroes/Hero.h"
#include <time.h>

class TimeNode;

namespace TimelineController{
    void addEvent(Hero* hero, Activities* act, int options);
    void run();
    void popMid(TimeNode* tn);
}

#endif