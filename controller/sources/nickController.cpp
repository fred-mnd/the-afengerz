#ifndef NICK_CONTROLLER_CPP
#define NICK_CONTROLLER_CPP

#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "../../etc/globals.h"
#include "../../etc/utils.h"
#include "../../model/heroes/Hero.h"
#include "../spacebar/actions/Activities.h"
#include "../spacebar/actions/activities/Nick.h"
#include "../headers/timelineController.h"
#include "../headers/gameController.h"

namespace NickController{

    Activities* act = new NickAct();
    void action(){
        Hero* hero = HeroNS::getHero(rand() % 6);
        if(GameController::getCurrHero() == hero) return;
        if(hero->getAct()){
            TimelineController::popMid(hero->getAct());
        }
        if(act->checkEligibility(hero) != 0) return;
        TimelineController::addEvent(hero, act, 0);
    }

    void run(){
        srand(time(0));
        if(!Utils::threadSleep(30)) return;
        while(!Globals::gameOver){
            if(rand() % 4 <= 1){
                action();
            }
            if(!Utils::threadSleep(60)) return;
        }
    }
}

#endif