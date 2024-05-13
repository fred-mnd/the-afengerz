#ifndef GAME_PAGE_CPP
#define GAME_PAGE_CPP

#include <array>
#include <conio.h>
#include <ctype.h>
#include "../../controller/headers/gameController.h"
#include "../../etc/utils.h"
#include "../../etc/globals.h"

namespace GamePage{

    void printRoom();
    void printHero();
    void control();

    void init(){
        GameController::init();
        Utils::cls();
        printRoom();
        control();
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
        } while(true);
    }


    void printRoom(){
        Utils::changeCursorPos(Globals::UP_LEFT);
        std::array<std::array<char, 31>, 15> map = GameController::getCurrMap();
        for(int i=0;i<15;i++){
            printf("%s\n", map[i]);
        }
    }

    void printHero(){
        Utils::changeCursorPos(GameController::getHeroPos(GameController::getCurrHero()));
        std::string print;
        GameController::getHeroPrintFormat(GameController::getCurrHero(), print);
        printf("%s", print.c_str());
    }
}

#endif