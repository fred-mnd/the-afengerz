#include <cstdlib>
#include <ctime>
#include "controller/headers/gameController.h"

using namespace std;

int main(){
    srand(time(0));
    GameController::init();
}