#ifndef GAME_CONTROLLER_CPP
#define GAME_CONTROLLER_CPP

#include "../../model/heroes/Hero.h"
#include "../../etc/utils.h"
#include "../../model/spacebar/actions/ChangeRoom.h"
#include "../headers/actionController.h"
#include <iostream>
#include <cstdlib>
#include <string>

namespace GameController{

    void changeBedroom();

    Hero* currHero;

    Hero* getCurrHero(){
        return currHero;
    }

    void init(){
        Utils::hideCursor();
        RoomNS::init();
        HeroNS::init();
        currHero = HeroNS::getHero(std::rand() % 6);
        changeBedroom();
    }

    std::array<std::array<char, 31>,15> getCurrMap(){
        return GameController::getCurrHero()->getCurrRoom()->getMap();
    }

    COORD getHeroPos(Hero* hero){
        return hero->getPos();
    }

    void getHeroPrintFormat(Hero* hero, std::string& print){
        char res[20];
        sprintf(res, "\e[%dm%c\e[39m", hero->getColor(), hero->getChar());
        print += res;
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
        else ActionController::setSpaceBar(NULL);
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