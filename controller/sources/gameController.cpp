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
        HeroNS::getHero(HeroNS::IRON_MAN)->getBedroom()->addFeatures({22,1}, {28, 8}, new UpgradeAct());

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
        currHero = HeroNS::getHero(std::rand() % 6);
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

    COORD getHeroPos(Hero* hero){
        return hero->getPos();
    }

    Room* checkNextRoom(short x, short y);

    void moveHero(short x, short y){
        COORD pos = currHero->getPos();
        Room* nextDoor = checkNextRoom(x, y);
        if(getCurrMap()[pos.Y + y][pos.X + x] != ' ' && !nextDoor) return;
        pos.X += x;
        pos.Y += y;
        currHero->setPos(pos);
        if(nextDoor){
            ActionController::setSpaceBar(new ChangeRoom(currHero, nextDoor));
        }
        else ActionController::setSpaceBar(getAct());
    }

    Room* checkNextRoom(short x, short y){
        for(Connection* conn : currHero->getCurrRoom()->getConn()){
            if(conn->door.X == currHero->getPos().X + x && conn->door.Y == currHero->getPos().Y + y){
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