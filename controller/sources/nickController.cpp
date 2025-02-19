#ifndef NICK_CONTROLLER_CPP
#define NICK_CONTROLLER_CPP

#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "../../etc/globals.h"
#include "../../etc/utils.h"
#include "../../model/heroes/Hero.h"
#include "../../model/timeline/Timeline.h"
#include "../spacebar/actions/Activities.h"
#include "../spacebar/actions/activities/Nick.h"
#include "../headers/timelineController.h"
#include "../headers/gameController.h"

namespace NickController{

    Activities* act;
    void action(){
        
        Hero* hero = HeroNS::getHero(rand() % 6);
        if(GameController::getCurrHero() == hero) return;
        if(act->checkEligibility(hero) != 0) return;
        if(hero->getAct()){
            hero->getAct()->act->forceRemove(hero);
            TimelineController::popMid(hero->getAct());
        }
        TimelineController::addEvent(hero, act, 0);
    }

    void run(){
        act = new NickAct();
        srand(time(0));
        if(!Utils::threadSleep(30)) return;
        while(!Globals::gameOver){
            Globals::timeline_mutex.lock();
            action();
            Globals::timeline_mutex.unlock();
            if(!Utils::threadSleep(90)) return;
        }
    }
}

#endif