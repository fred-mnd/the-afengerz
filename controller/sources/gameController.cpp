#ifndef GAME_CONTROLLER_CPP
#define GAME_CONTROLLER_CPP

#include "../../model/heroes/Hero.h"
#include "../../etc/utils.h"
#include "../spacebar/actions/ChangeRoom.h"
#include "../spacebar/actions/Activities.h"
#include "../spacebar/actions/activities/Upgrade.h"
#include "../headers/actionController.h"
#include "../headers/timelineController.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>

namespace GameController{

    void changeBedroom();

    Hero* currHero;
    std::thread *timelineThread;

    std::thread *getTimelineThread(){
        return timelineThread;
    }

    Hero* getCurrHero(){
        return currHero;
    }

    void addSpecialty(){
        HeroNS::getHero(HeroNS::IRON_MAN)->getBedroom()->addFeatures({22,1}, {28, 8}, new UpgradeAct({25, 1}, HeroNS::getHero(HeroNS::IRON_MAN)->getBedroom()));

    }

    void test(){
        TimelineController::run();
    }

    void init(){
        timelineThread = new std::thread(TimelineController::run);
        // timelineThread = new std::thread(test);
        Utils::hideCursor();
        RoomNS::init();
        HeroNS::init();
        addSpecialty();
        // currHero = HeroNS::getHero(std::rand() % 6);
        currHero = HeroNS::getHero(4);
        changeBedroom();
    }

    Activities* getAct(){
        COORD pos = currHero->getPos();
        for(Features* feat : currHero->getCurrRoom()->getFeat()){
            if(feat->checkNear(pos)){
                return feat->getAct();
            }
        }
        return NULL;
    }

    std::array<std::array<char, 31>,15> getCurrMap(){
        return GameController::getCurrHero()->getCurrRoom()->getMap();
    }

    Room* checkNextRoom(COORD newPos);

    void moveHero(COORD newPos){
        Room* nextDoor = checkNextRoom(newPos);
        if(getCurrMap()[newPos.Y][newPos.X] != ' ' && !nextDoor) return;
        currHero->setPos(newPos);
        if(nextDoor){
            ActionController::setSpaceBar(new ChangeRoom(currHero, nextDoor));
        }
        else ActionController::setSpaceBar(getAct());
    }

    Room* checkNextRoom(COORD newPos){
        for(Connection* conn : currHero->getCurrRoom()->getConn()){
            if(conn->door.X == newPos.X && conn->door.Y == newPos.Y){
                return conn->room;
            }
        }
        return NULL;
    }

    void changeBedroom(){
        RoomNS::getRoom(RoomNS::LIVING_ROOM)->changeRelationship(0, GameController::getCurrHero()->getBedroom());
    }

}

#endif