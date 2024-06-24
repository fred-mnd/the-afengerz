#ifndef TIMELINE_CONTROLLER_CPP
#define TIMELINE_CONTROLLER_CPP

#include "../../model/heroes/Hero.h"
#include "../../model/timeline/Timeline.h"
#include "../../view/headers/gamePage.h"
#include "../../model/map/Room.h"
#include "../../etc/globals.h"
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
        int change = act->start(options);
        TimeNode* newNode = timeline->pushMid(clock() + act->getDuration() * CLOCKS_PER_SEC, hero, act);
        newNode->change = change;
        if(hero->getCurrRoom() != act->getRoom() && newNode->change != -10){
            hero->setCurrRoom(act->getRoom());
            hero->setPos(hero->getCurrRoom()->getSafePos());
        }
        hero->setAct(newNode);
        act->getRoom()->addHero(hero);
        GamePage::printStatus();
        refreshUI(act);
    }

    void endEvent(){
        Activities* act = timeline->popHead();
        GamePage::printStatus();
        refreshUI(act);
    }

    void run(){
        while(!Globals::gameOver){
            Globals::timeline_mutex.lock();
            if(timeline->isEmpty()){
                Globals::timeline_mutex.unlock();
                continue;
            }
            while(timeline->isHead() && clock() >= timeline->getHeadTime()){
                endEvent();
            }
            Globals::timeline_mutex.unlock();
        }
    }

    void popMid(TimeNode* tn){
        Activities* act = timeline->popMid(tn);
        refreshUI(act);
    }
}

#endif