#ifndef ROOM_CPP
#define ROOM_CPP

#include "Room.h"
#include "../../controller/headers/gameController.h"
#include <array>

namespace RoomNS{
    std::array<Room*, 6> rooms;

    Room* getRoom(int index){
        return rooms[index];
    }

    void init(){
        rooms[0] = new Room("living-room");

        // connect
        rooms[RoomNS::LIVING_ROOM]->addRelationship(1, 14, NULL);
    }

    void changeBedroom(){
        rooms[RoomNS::LIVING_ROOM]->changeRelationship(0, GameController::getCurrHero()->getBedroom());
    }
}

#endif