#ifndef MEETING_PAGE_CPP
#define MEETING_PAGE_CPP

#include "../../etc/utils.h"
#include "../../etc/globals.h"
#include "../../controller/headers/gameController.h"
#include "../../controller/headers/actionController.h"
#include "../../controller/headers/timelineController.h"

namespace MeetingPage{

    void printMenu(){
        puts("You are about to initiate a meeting.\n");
        printf("Press Space to start a meeting");
        puts("");
    }

    void control(){
        do{
            if(Utils::isInput()){
                char key = Utils::getKeyInput();
                if(key == ' '){
                    Globals::timeline_mutex.lock();
                    for(int i=0;i<6;i++){
                        printf("%d", i);
                        TimelineController::addEvent(HeroNS::getHero(i), ActionController::getAct(), i);
                    }
                    Globals::timeline_mutex.unlock();
                    return;
                }
                else if(key == 27){
                    return;
                }
            }
        } while(!Globals::gameOver);
    }

    void show(){
        Utils::cls();
        Utils::printHeroCoded(GameController::getCurrHero(), "Meeting Room\n-------------\n\n");

        printMenu();
        control();
    }
}

#endif