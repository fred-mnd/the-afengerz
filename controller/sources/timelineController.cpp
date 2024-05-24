#ifndef TIMELINE_CONTROLLER_CPP
#define TIMELINE_CONTROLLER_CPP

#include "../../model/heroes/Hero.h"
#include "../../model/timeline/Timeline.h"
#include <time.h>

namespace TimelineController{

    Timeline* timeline = new Timeline();
    void addEvent(int duration, Hero* hero, Activities* act){
        hero->setAct(act);
        timeline->pushMid(clock() + duration * CLOCKS_PER_SEC, hero);
        timeline->view();
    }
}

#endif