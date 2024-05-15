#ifndef GAME_PAGE_CPP
#define GAME_PAGE_CPP

#include <array>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include "../../controller/headers/gameController.h"
#include "../../etc/utils.h"
#include "../../etc/globals.h"
#include "../../model/spacebar/SpaceBar.h"
#include "../../controller/headers/actionController.h"

namespace GamePage{

    void printRoom();
    void printHero();
    void control();
    void show();
    void clearText(COORD coor);

    void printText(COORD coor, std::string message){
        clearText(coor);
        printf("%s", message.c_str());
    }

    void init(){
        GameController::init();
        show();
    }

    void show(){
        Utils::cls();
        printRoom();
        control();
    }

    void clearText(COORD coor){
        Utils::changeCursorPos(coor);
        printf("\e[K");
    }

    void control(){
        do{
            printHero();
            char key = tolower(getch());
            if(key == 'd'){
                GameController::moveHero(1, 0);
            }
            else if(key == 'a'){
                GameController::moveHero(-1, 0);
            }
            else if(key == 'w'){
                GameController::moveHero(0, -1);
            }
            else if(key == 's'){
                GameController::moveHero(0, 1);
            }
            else if(key == ' '){
                ActionController::action();
            }
            clearText(Globals::ACTION_MESSAGE);
            if(SpaceBar* mess = ActionController::hasAction()) printText(Globals::ACTION_MESSAGE, mess->getMessage());
        } while(true);
    }

    void printRoom(){
        Utils::changeCursorPos(Globals::UP_LEFT);
        std::array<std::array<char, 31>, 15> map = GameController::getCurrMap();
        for(int i=0;i<15;i++){
            printf("%s\n", map[i]);
        }

        printText(Globals::ROOM_NAME, GameController::getCurrHero()->getCurrRoom()->getName().c_str());
    }

    void printHero(){
        Utils::changeCursorPos(GameController::getHeroPos(GameController::getCurrHero()));
        std::string print;
        GameController::getHeroPrintFormat(GameController::getCurrHero(), print);
        printf("%s", print.c_str());
    }
}

#endif