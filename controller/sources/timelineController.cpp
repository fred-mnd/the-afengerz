#ifndef TIMELINE_CONTROLLER_CPP
#define TIMELINE_CONTROLLER_CPP

#include "../../model/heroes/Hero.h"
#include "../../model/timeline/Timeline.h"
#include <time.h>
#include <thread>

namespace TimelineController{

    Timeline* timeline = new Timeline();
    void addEvent(int duration, Hero* hero, Activities* act, int options){
        hero->setAct(act);
        timeline->pushMid(clock() + duration * CLOCKS_PER_SEC, hero);
    }

    void endEvent(){
        Hero* hero = timeline->popHead();
        hero->getAct()->end();
        hero->setAct(NULL);
    }

    void run(){
        while(true){
            while(timeline->isHead() && clock() >= timeline->getHeadTime()){
                endEvent();
            }
        }
    }
}

#endif