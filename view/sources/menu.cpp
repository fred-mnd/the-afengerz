#ifndef MENU_CPP
#define MENU_CPP

#include "../../etc/utils.h"
#include "../../etc/globals.h"
#include "../headers/gamePage.h"
#include "../../controller/headers/scoreController.h"

namespace Menu{
    short x = 13;
    short y = 3;
    short options = 0;

    void printMenu(){
        puts("Play!");
        puts("High Score");
        puts("Exit");
    }

    void printArrow(){
        Utils::changeCursorPos({x, short(y + options-1)});
        printf("<");
    }

    void changeArrow(short inc){
        short temp = options + inc;
        if(temp > 2 || temp < 0) return;
        Utils::clearText({x, short(y + options-1)});
        options = temp;
        printArrow();
    }

    void highScore(){
        bool highscore = true;
        do{
            Utils::cls();
            puts("High Score\n----------------\n");
            ScoreController::view(highscore);
            Utils::clearText({50, 6});
            printf("Press S to sort by %s or Space to exit", highscore? "Name" : "Score");
            char key;
            do{
                key = Utils::getKeyInput();
                if(key == 's' || key == ' ') break;
            } while(true);
            if(key == 's') highscore = !highscore;
            else if(key == ' ') return;
        } while(true);
    }

    void show();

    void exit(){
        Utils::cls();
        int len = sizeof(Globals::logo) / sizeof(Globals::logo[0]);
        for(int i=0;i<len;i++){
            printf("%s\n", Globals::logo[i]);
            Sleep(10);
        }
        Utils::getKeyInput();
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
                if(options == 0){
                    GamePage::init();
                }
                else if(options == 1){
                    highScore();
                }
                else{
                    exit();
                    return;
                }
                show();
            }
        } while(true);
    }

    void show(){
        Utils::cls();
        Utils::hideCursor();
        puts("Welcome to The AFengerZ!\n");

        printMenu();
        printArrow();
        control();
    }
}

#endif