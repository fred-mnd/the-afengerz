#ifndef SUPERHERO_CONTROLLER_CPP
#define SUPERHERO_CONTROLLER_CPP

#include "../../etc/globals.h"
#include "../../etc/utils.h"
#include "../../model/heroes/Hero.h"
#include "../../model/map/Room.h"
#include "../headers/gameController.h"
#include "../spacebar/actions/Activities.h"
#include "../headers/timelineController.h"
#include <windows.h>

namespace SupController{
    Hero* getHero(){
        Hero* hero;
        do{
            hero = HeroNS::getHero(rand() % 6);
        } while(hero == GameController::getCurrHero());
        return hero;
    }

    Room* getRoom(Hero* hero){
        int idx = rand() % 4 + 1;
        Room* room;
        if(idx == RoomNS::MEETING_ROOM) room = hero->getBedroom();
        else room = RoomNS::getRoom(idx);

        return room;
    }

    Activities* getAct(Room* room){
        return (Activities*) room->getFeat()[rand() % room->getFeat().size()]->getAct();
    }

    void act(){
        Hero* hero = getHero();
        if(hero->getAct()) return;

        Room* room = getRoom(hero);
        
        Activities* act = getAct(room);
        if(act->checkEligibility(hero) != 0) return;

        TimelineController::addEvent(hero, act, rand() % 3);
    }

    void run(){
        srand(time(0));
        if(!Utils::threadSleep(10)) return;
        while(!Globals::gameOver){
            Globals::timeline_mutex.lock();
            act();
            Globals::timeline_mutex.unlock();
            if(!Utils::threadSleep(30)) return;
        }
    }
}

#endif