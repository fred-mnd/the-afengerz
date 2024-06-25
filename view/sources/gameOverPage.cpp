#ifndef GAME_OVER_CPP
#define GAME_OVER_CPP

#include <string>
#include "../../etc/utils.h"
#include "../../controller/headers/gameController.h"
#include "ctype.h"

namespace GameOverPage{

    std::string name;

    bool checkName(std::string name){
        int len = name.length();
        if(len < 3){
            printf("Name must be at least 3 characters long.\n");
            return false;
        }

        for(int i=0;i<len;i++){
            if(!isalpha(name[i])){
                printf("Name must only contain letters.\n");
                return false;
            }
        }
        return true;
    }

    void show(){
        Utils::cls();
        puts("Game Over!");
        printf("Your Score : %d\n\n", GameController::getScore());
        puts("Input your name:");
        char temp[200];
        do{
            printf(">> ");
            scanf("%[^\n]", temp); getchar();
            name = temp;
        } while(!checkName(name));
    }

    void init(){
        name = "";
        Utils::showCursor();
        show();
    }
}

#endif