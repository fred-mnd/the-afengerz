#ifndef ROOM_CPP
#define ROOM_CPP

#include "Room.h"
#include "../../controller/spacebar/actions/activities/Training.h"
#include "../../controller/spacebar/actions/activities/Upgrade.h"
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
        rooms[4] = new Room("restaurant", "Restaurant");

        // connect
        rooms[RoomNS::LIVING_ROOM]->addRelationship(14, 0, NULL);
        rooms[RoomNS::LIVING_ROOM]->addRelationship(10, 14, rooms[RoomNS::MEETING_ROOM]);
        rooms[RoomNS::LIVING_ROOM]->addRelationship(0, 9, rooms[RoomNS::TRAINING_ROOM]);
        rooms[RoomNS::LIVING_ROOM]->addRelationship(29, 5, rooms[RoomNS::RESTAURANT]);

        rooms[RoomNS::MEETING_ROOM]->addRelationship(7, 0, rooms[RoomNS::LIVING_ROOM]);

        rooms[RoomNS::TRAINING_ROOM]->addRelationship(29, 3, rooms[RoomNS::LIVING_ROOM]);
        rooms[RoomNS::TRAINING_ROOM]->addRelationship(25, 14, rooms[RoomNS::WORKSHOP]);

        rooms[RoomNS::WORKSHOP]->addRelationship(24, 0, rooms[RoomNS::TRAINING_ROOM]);

        rooms[RoomNS::RESTAURANT]->addRelationship(0, 11, rooms[RoomNS::LIVING_ROOM]);

        // features
        rooms[RoomNS::TRAINING_ROOM]->addFeatures({22, 7}, {22, 7}, new TrainingAct());
        rooms[RoomNS::WORKSHOP]->addFeatures({16, 7}, {16, 7}, new UpgradeAct());

    }
}

#endif