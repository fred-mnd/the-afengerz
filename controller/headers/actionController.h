#ifndef ACTION_CONTROLLER_H
#define ACTION_CONTROLLER_H

#include "../../model/spacebar/SpaceBar.h"

namespace ActionController{
    void setSpaceBar(SpaceBar* space);
    void action();
    SpaceBar* hasAction();
}

#endif