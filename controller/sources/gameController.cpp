#ifndef GAME_CONTROLLER_CPP
#define GAME_CONTROLLER_CPP

#include "../../model/heroes/Hero.h"
#include "../../etc/utils.h"
#include <iostream>
#include <cstdlib>
#include <string>

namespace GameController{

    Hero* currHero;

    Hero* getCurrHero(){
        return currHero;
    }

    void init(){
        Utils::hideCursor();
        RoomNS::init();
        HeroNS::init();
        currHero = HeroNS::getHero(std::rand() % 6);
        // currHero = HeroNS::getHero(HeroNS::HULK);
        RoomNS::changeBedroom();
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

    void moveHero(short x, short y, std::string& message){
        COORD pos = currHero->getPos();
        Room* nextDoor = checkNextRoom(x, y);
        if(getCurrMap()[pos.Y + y][pos.X + x] != ' ' && !nextDoor) return;
        Utils::changeCursorPos(pos);
        printf("%c", getCurrMap()[pos.Y][pos.X]);
        pos.X += x;
        pos.Y += y;
        currHero->setPos(pos);
        if(nextDoor){
            message = "Press Space to go to " + nextDoor->getName();
        }
        else message = "";
    }

    Room* checkNextRoom(short x, short y){
        for(Connection* conn : currHero->getCurrRoom()->getConn()){
            if(conn->door.X == currHero->getPos().X + x && conn->door.Y == currHero->getPos().Y + y){
                return conn->room;
            }
        }
        return NULL;
    }
}

#endif