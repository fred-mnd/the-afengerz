#ifndef GAME_PAGE_CPP
#define GAME_PAGE_CPP

#include <array>
#include <windows.h>
#include "../../controller/headers/gameController.h"
#include "../../etc/utils.h"
#include "../../etc/globals.h"
#include "../../controller/spacebar/SpaceBar.h"
#include "../../controller/headers/actionController.h"
#include "../../model/timeline/Timeline.h"
#include "../../model/map/Room.h"
#include "../headers/gamePage.h"
#include "mutex"

namespace GamePage{

    std::mutex m;

    void printRoom();
    void printHero(Hero* hero, COORD pos);
    void control();
    void show();

    bool inUI;

    bool isInUI(){
        return inUI;
    }

    void printText(COORD coor, std::string message){
        Utils::clearText(coor);
        printf("%s", message.c_str());
    }

    void init(){
        GameController::init();
        show();
        inUI = true;
        control();
        GameController::getTimelineThread()->join();
        GameController::getSupThread()->join();
    }

    void show(){
        Utils::cls();
        printRoom();
    }

    void changeHeroPos(COORD oldPos, COORD newPos){
        m.lock();
        Utils::changeCursorPos(oldPos);
        printf("%c", GameController::getCurrHero()->getCurrRoom()->getMap()[oldPos.Y][oldPos.X]);
        GameController::moveHero(newPos);
        m.unlock();
    }

    void moveHero(short x, short y){
        COORD pos = GameController::getCurrHero()->getPos();
        changeHeroPos(pos, {(short)(pos.X + x), (short)(pos.Y + y)});
    }

    void control(){
        do{
            inUI = true;
            if(!GameController::getCurrHero()->getAct()) printHero(GameController::getCurrHero(), GameController::getCurrHero()->getPos());
            char key = Utils::getKeyInput();
            if(key == 'p'){
                inUI = false;
                if(!GameController::changeHero()){
                    printText(Globals::ACTION_MESSAGE, "You currently can't switch hero");
                }
            }
            else if(GameController::getCurrHero()->getAct()) continue;
            else if(key == 'd'){
                moveHero(1, 0);
            }
            else if(key == 'a'){
                moveHero(-1, 0);
            }
            else if(key == 'w'){
                moveHero(0, -1);
            }
            else if(key == 's'){
                moveHero(0, 1);
            }
            else if(key == ' '){
                inUI = false;
                ActionController::action();
            }
            Utils::clearText(Globals::ACTION_MESSAGE);
            if(SpaceBar* mess = ActionController::hasAction()) printText(Globals::ACTION_MESSAGE, mess->getMessage());
        } while(true);
    }

    void printRoom(){
        m.lock();
        Utils::changeCursorPos(Globals::UP_LEFT);
        std::array<std::array<char, 31>, 15> map = GameController::getCurrMap();
        for(int i=0;i<15;i++){
            printf("%s\n", map[i]);
        }
        for(Hero* hero : GameController::getCurrHero()->getCurrRoom()->getHeroList()){
            printHero(hero, hero->getAct()->pos);
        }
        printText(Globals::ROOM_NAME, GameController::getCurrHero()->getCurrRoom()->getName().c_str());
        m.unlock();
    }

    void printHero(Hero* hero, COORD pos){
        Utils::changeCursorPos(pos);
        Utils::printHeroCoded(hero, hero->getChar());
    }

    void refreshUI(){
        printRoom();
        if(!GameController::getCurrHero()->getAct()) printHero(GameController::getCurrHero(), GameController::getCurrHero()->getPos());
    }
}

#endif