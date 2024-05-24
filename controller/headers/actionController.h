#ifndef ACTION_CONTROLLER_H
#define ACTION_CONTROLLER_H

#include "../spacebar/SpaceBar.h"
#include "../spacebar/actions/Activities.h"

namespace ActionController{
    void setSpaceBar(SpaceBar* space);
    int action();
    SpaceBar* hasAction();
    Activities* getAct();
}

#endif