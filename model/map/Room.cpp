#ifndef ROOM_CPP
#define ROOM_CPP

#include "Room.h"

namespace RoomNS{
    Room* rooms[6];

    Room* getRoom(int index){
        return rooms[index];
    }

    void init(){
        
    }
}

#endif