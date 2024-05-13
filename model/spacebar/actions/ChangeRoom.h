#ifndef CHANGE_ROOM_H
#define CHANGE_ROOM_H

#include "../SpaceBar.h"
#include "../../map/Room.h"
#include "../../../controller/headers/gameController.h"

class ChangeRoom : public SpaceBar{
private:
    Room* nextRoom;
public:
    ChangeRoom(std::string message, Room* room): SpaceBar(message){
        nextRoom = room;
    }

    Room* getRoom(){
        return nextRoom;
    }
};

#endif