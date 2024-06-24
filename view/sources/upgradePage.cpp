#ifndef UPGRADE_PAGE_CPP
#define UPGRADE_PAGE_CPP

#include "../../etc/utils.h"
#include "../../etc/globals.h"
#include "../../controller/headers/gameController.h"
#include "../../controller/headers/actionController.h"
#include "../../controller/headers/timelineController.h"

namespace UpgradePage{

    short x = 13;
    short y = 4;
    short options = 2;

    void printMenu(){
        int health = GameController::getCurrHero()->getEqHealth();
        printf("Current Equipment Health : %d/100\n\n", health);

        if(health >= 80) options = 0;
        else if(health >= 50) options = 1;
        printf("Repair Time : %s\n\n", Utils::printTime(ActionController::getAct()->getDurationFromArray(options)).c_str());
        printf("Press Space to confirm repair");
        puts("");
    }

    void control(){
        do{
            char key = Utils::getKeyInput();
            if(key == ' '){
                Globals::timeline_mutex.lock();
                TimelineController::addEvent(GameController::getCurrHero(), ActionController::getAct(), options);
                Globals::timeline_mutex.unlock();
                return;
            }
            else if(key == 27){
                return;
            }
        } while(true);
    }

    void show(){
        Utils::cls();
        Utils::printHeroCoded(GameController::getCurrHero(), "Workshop\n-------------\n\n");

        printMenu();
        control();
    }
}

#endif