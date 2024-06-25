#include <cstdlib>
#include <ctime>
#include "view/headers/menu.h"
#include "controller/headers/scoreController.h"
#include "etc/utils.h"
#include <iostream>

using namespace std;

int main(){
    system(" ");
    srand(time(0));
    ScoreController::init();
    while(Menu::show());
    
}