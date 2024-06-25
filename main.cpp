#include <cstdlib>
#include <ctime>
#include "view/headers/gamePage.h"
#include "controller/headers/scoreController.h"
#include "etc/utils.h"
#include <iostream>

using namespace std;

int main(){
    system(" ");
    srand(time(0));
    ScoreController::init();
    GamePage::init();
    ScoreController::view(0);
}