#ifndef ACTION_CONTROLLER_CPP
#define ACTION_CONTROLLER_CPP

#include "../spacebar/SpaceBar.h"
#include "../spacebar/actions/ChangeRoom.h"
#include "../../model/map/Room.h"
#include "../../view/headers/gamePage.h"
#include "../headers/gameController.h"
#include "../spacebar/actions/Activities.h"

namespace ActionController{
    SpaceBar* spacebar;

    void setSpaceBar(SpaceBar* space){
        spacebar = space;
    }

    Activities* getAct(){
        return (Activities*) spacebar;
    }

    void action(){
        if(!spacebar) return;
        if(spacebar->action()){
            spacebar = NULL;
            GamePage::show();
        }
    }

    SpaceBar* hasAction(){
        return spacebar;
    }
}

#endif