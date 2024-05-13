#include <cstdlib>
#include <ctime>
#include "controller/headers/gameController.h"
#include "view/headers/gamePage.h"
#include <array>

using namespace std;

int main(){
    srand(time(0));
    GameController::init();
    GamePage::printRoom();
    
}