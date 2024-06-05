#ifndef CHANGE_HERO_PAGE_CPP
#define CHANGE_HERO_PAGE_CPP

#include "../../etc/utils.h"
#include "../../controller/headers/gameController.h"
#include "../../controller/headers/actionController.h"
#include "../../controller/headers/timelineController.h"

namespace ChangeHeroPage{

    short x = 21;
    short y = 4;
    short options = 0;

    void printMenu(){
        for(int i=0;i<6;i++){
            Hero* currHero = HeroNS::getHero(i);
            Utils::printHeroCoded(currHero, currHero->getChar());
            printf(" - %s\n", currHero->getName().c_str());
        }
    }

    void printArrow(){
        Utils::changeCursorPos({x, short(y + options-1)});
        Utils::printHeroCoded(GameController::getCurrHero(), '<');
    }

    void changeArrow(short inc){
        short temp = options + inc;
        if(temp > 5 || temp < 0) return;
        Utils::clearText({x, short(y + options-1)});
        options = temp;
        printArrow();
    }

    void changeHero(){
        GameController::setCurrHero(HeroNS::getHero(options));
        GameController::changeBedroom();
    }

    void control(){
        do{
            char key = Utils::getKeyInput();
            if(key == 'w'){
               changeArrow(-1);
            }
            else if(key == 's'){
                changeArrow(1);
            }
            else if(key == ' '){
                changeHero();
                return;
            }
            else if(key == 27){
                return;
            }
        } while(true);
    }

    void show(){
        Utils::cls();
        Utils::printHeroCoded(GameController::getCurrHero(), "Change Avenger\n-------------\n\n");

        printMenu();
        printArrow();
        control();
    }
}

#endif