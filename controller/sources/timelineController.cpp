#ifndef TIMELINE_CONTROLLER_CPP
#define TIMELINE_CONTROLLER_CPP

#include "../../model/heroes/Hero.h"
#include "../../model/timeline/Timeline.h"
#include "../../view/headers/gamePage.h"
#include "../headers/gameController.h"
#include <time.h>
#include <thread>

namespace TimelineController{

    void refreshUI(Activities* act){
        if(act->getRoom() == GameController::getCurrHero()->getCurrRoom() && GamePage::isInUI()){
            GamePage::refreshUI();
        }
    }

    Timeline* timeline = new Timeline();
    void addEvent(int duration, Hero* hero, Activities* act, int options){
        act->start(options);
        act->getRoom()->addHero(hero);
        hero->setAct(act);
        timeline->pushMid(clock() + duration * CLOCKS_PER_SEC, hero);
        refreshUI(act);
    }

    void endEvent(){
        Hero* hero = timeline->popHead();
        Activities* act = hero->getAct();
        act->end(hero);
        act->getRoom()->removeHero(hero);
        hero->setAct(NULL);
        refreshUI(act);
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