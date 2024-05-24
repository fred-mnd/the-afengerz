#ifndef TIMELINE_CONTROLLER_H
#define TIMELINE_CONTROLLER_H

#include "../../model/heroes/Hero.h"
#include <time.h>

namespace TimelineController{
    void addEvent(int duration, Hero* hero, Activities* act);
    
}

#endif