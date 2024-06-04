#ifndef TRAINING_PAGE_CPP
#define TRAINING_PAGE_CPP

#include "../../etc/utils.h"
#include "../../controller/headers/gameController.h"
#include "../../controller/headers/actionController.h"
#include "../../controller/headers/timelineController.h"

namespace TrainingPage{

    short x = 13;
    short y = 4;
    short options = 0;

    void printMenu(){
        puts("Theory");
        puts("Practice");
        puts("Simulation");
    }

    void printArrow(){
        Utils::changeCursorPos({x, short(y + options-1)});
        Utils::printHeroCoded(GameController::getCurrHero(), '<');
    }

    void changeArrow(short inc){
        short temp = options + inc;
        if(temp > 2 || temp < 0) return;
        Utils::clearText({x, short(y + options-1)});
        options = temp;
        printArrow();
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
                TimelineController::addEvent(GameController::getCurrHero(), ActionController::getAct(), options);
                return;
            }
            else if(key == 27){
                return;
            }
        } while(true);
    }

    void show(){
        Utils::cls();
        Utils::printHeroCoded(GameController::getCurrHero(), "Training Modes\n-------------\n\n");

        printMenu();
        printArrow();
        control();
    }
}

#endif