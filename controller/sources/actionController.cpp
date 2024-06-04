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

    // COORD checkCoordinate(Room* room, Room* prevRoom){
    //     for(Connection* conn : room->getConn()){
    //         if(conn->room == prevRoom){
    //             return conn->door;
    //         }
    //     }
    //     return {0,0};
    // }

    void action(){
        if(!spacebar) return;
        spacebar->action();
        GamePage::show();
    }

    SpaceBar* hasAction(){
        return spacebar;
    }

}

#endif