#ifndef GAME_CONTROLLER_CPP
#define GAME_CONTROLLER_CPP

#include "../../model/heroes/Hero.h"
#include "../../view/headers/changeHeroPage.h"
#include "../../view/headers/gamePage.h"
#include "../../etc/utils.h"
#include "../../etc/globals.h"
#include "../spacebar/actions/ChangeRoom.h"
#include "../spacebar/actions/Activities.h"
#include "../spacebar/actions/activities/Upgrade.h"
#include "../headers/actionController.h"
#include "../headers/timelineController.h"
#include "../headers/superheroController.h"
#include "../headers/nickController.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>

namespace GameController{

    void changeBedroom();

    Hero* currHero;
    std::thread *timelineThread;
    std::thread *supThread;
    std::thread *nickThread;

    int score;

    int getScore(){
        return score;
    }

    int addScore(int add){
        score += add;
    }

    std::thread *getTimelineThread(){
        return timelineThread;
    }

    std::thread *getSupThread(){
        return supThread;
    }

    std::thread *getNickThread(){
        return nickThread;
    }

    Hero* getCurrHero(){
        return currHero;
    }

    void setCurrHero(Hero* hero){
        currHero = hero;
    }

    void addSpecialty(){
        HeroNS::getHero(HeroNS::IRON_MAN)->getBedroom()->addFeatures({22,1}, {28, 8}, new UpgradeAct({25, 1}, HeroNS::getHero(HeroNS::IRON_MAN)->getBedroom()));
    }

    void test(){
        TimelineController::run();
    }

    void init(){
        Globals::gameOver = false;
        timelineThread = new std::thread(TimelineController::run);
        supThread = new std::thread(SupController::run);
        nickThread = new std::thread(NickController::run);
        score = 0;
        Utils::hideCursor();
        RoomNS::init();
        HeroNS::init();
        addSpecialty();
        currHero = HeroNS::getHero(std::rand() % 6);
        changeBedroom();
    }

    SpaceBar* getAct(){
        COORD pos = currHero->getPos();
        for(Features* feat : currHero->getCurrRoom()->getFeat()){
            if(feat->checkNear(pos)){
                feat->getAct()->setPrompt();
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

    bool changeHero(){
        if(currHero->getCurrRoom() == currHero->getBedroom() || currHero->getAct()){
            ChangeHeroPage::show();
            ActionController::setSpaceBar(NULL);
            GamePage::show();
            return true;
        }
        return false;
    }

}

#endif