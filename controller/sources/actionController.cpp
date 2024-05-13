#ifndef ACTION_CONTROLLER_CPP
#define ACTION_CONTROLLER_CPP

#include "../../model/spacebar/SpaceBar.h"
#include "../../model/spacebar/actions/ChangeRoom.h"
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

    void action(){
        if(!spacebar) return;
        if(ChangeRoom* change = dynamic_cast<ChangeRoom*>(spacebar)){
            Room* nextRoom = change->getRoom();
            COORD nextCoord = checkCoordinate(nextRoom, GameController::getCurrHero()->getCurrRoom());
            setSpaceBar(new ChangeRoom("Press Space to go to " + GameController::getCurrHero()->getCurrRoom()->getName(), GameController::getCurrHero()->getCurrRoom()));
            GameController::getCurrHero()->setCurrRoom(nextRoom);
            GameController::getCurrHero()->setPos(nextCoord);
            GamePage::printRoom();
        }
    }

    SpaceBar* hasAction(){
        return spacebar;
    }

}

#endif