#ifndef ROOM_CPP
#define ROOM_CPP

#include "Room.h"
#include "../../controller/headers/gameController.h"

namespace RoomNS{
    Room* rooms[6];

    Room* getRoom(int index){
        return rooms[index];
    }

    void init(){
        rooms[0] = new Room("living-room");

        // connect
    }

    void changeBedroom(){
        rooms[RoomNS::LIVING_ROOM]->addRelationship(1, 14, GameController::getCurrHero()->getBedroom());
    }
}

#endif