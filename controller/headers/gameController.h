#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "../../model/heroes/Hero.h"

namespace GameController{
    Hero* getCurrHero();
    void init();
}

#endif