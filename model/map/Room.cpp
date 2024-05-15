#ifndef ROOM_CPP
#define ROOM_CPP

#include "Room.h"
#include <array>

namespace RoomNS{
    std::array<Room*, 6> rooms;

    Room* getRoom(int index){
        return rooms[index];
    }

    void init(){
        rooms[0] = new Room("living-room", "Living Room");
        rooms[1] = new Room("meeting-room", "Meeting Room");
        rooms[2] = new Room("training-room", "Training Room");
        rooms[3] = new Room("workshop", "Workshop");

        // connect
        rooms[RoomNS::LIVING_ROOM]->addRelationship(14, 0, NULL);
        rooms[RoomNS::LIVING_ROOM]->addRelationship(10, 14, rooms[RoomNS::MEETING_ROOM]);
        rooms[RoomNS::LIVING_ROOM]->addRelationship(0, 9, rooms[RoomNS::TRAINING_ROOM]);

        rooms[RoomNS::MEETING_ROOM]->addRelationship(7, 0, rooms[RoomNS::LIVING_ROOM]);

        rooms[RoomNS::TRAINING_ROOM]->addRelationship(29, 3, rooms[RoomNS::LIVING_ROOM]);
        rooms[RoomNS::TRAINING_ROOM]->addRelationship(25, 14, rooms[RoomNS::WORKSHOP]);

        rooms[RoomNS::WORKSHOP]->addRelationship(24, 0, rooms[RoomNS::TRAINING_ROOM]);

    }
}

#endif