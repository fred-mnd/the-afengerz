#ifndef SUPERHERO_CONTROLLER_CPP
#define SUPERHERO_CONTROLLER_CPP

#include "../../etc/globals.h"
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
        // int idx = rand() % 4 + 1;
        int idx = RoomNS::RESTAURANT;
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

        // TimelineController::addEvent(hero, act, rand() % 3);
        TimelineController::addEvent(hero, act, 0);
    }

    void run(){
        srand(time(0));
        Sleep(15000);
        while(!Globals::gameOver){
            act();
            Sleep(30000);
        }
    }
}

#endif