#ifndef TIMELINE_CONTROLLER_CPP
#define TIMELINE_CONTROLLER_CPP

#include "../../model/heroes/Hero.h"
#include "../../model/timeline/Timeline.h"
#include "../../view/headers/gamePage.h"
#include "../../model/map/Room.h"
#include "../headers/gameController.h"
#include "../spacebar/actions/Activities.h"
#include "../spacebar/actions/activities/Upgrade.h"
#include <time.h>
#include <thread>

namespace TimelineController{

    void refreshUI(Activities* act){
        if(act->getRoom() == GameController::getCurrHero()->getCurrRoom() && GamePage::isInUI()){
            GamePage::refreshUI();
        }
    }

    Timeline* timeline = new Timeline();
    void addEvent(Hero* hero, Activities* act, int options){
        act->start(options);
        hero->setAct(act);
        act->getRoom()->addHero(hero);
        timeline->pushMid(clock() + act->getDuration(options) * CLOCKS_PER_SEC, hero);
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