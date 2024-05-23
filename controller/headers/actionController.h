#ifndef ACTION_CONTROLLER_H
#define ACTION_CONTROLLER_H

#include "../spacebar/SpaceBar.h"

namespace ActionController{
    void setSpaceBar(SpaceBar* space);
    int action();
    SpaceBar* hasAction();
}

#endif