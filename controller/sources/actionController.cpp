#ifndef ACTION_CONTROLLER_CPP
#define ACTION_CONTROLLER_CPP

#include "../spacebar/SpaceBar.h"
#include "../spacebar/actions/ChangeRoom.h"
#include "../../model/map/Room.h"
#include "../../view/headers/gamePage.h"
#include "../headers/gameController.h"

namespace ActionController{
    SpaceBar* spacebar;

    void setSpaceBar(SpaceBar* space){
        spacebar = space;
    }

    COORD checkCoordinate(Room* room, Room* prevRoom){
        for(Connection* conn : room->getConn()){
            if(conn->room == prevRoom){
                return conn->door;
            }
        }
        return {0,0};
    }

    int action(){
        if(!spacebar) return -1;
        return spacebar->action();
        
    }

    SpaceBar* hasAction(){
        return spacebar;
    }

}

#endif