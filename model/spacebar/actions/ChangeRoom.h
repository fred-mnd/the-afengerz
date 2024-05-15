#ifndef CHANGE_ROOM_H
#define CHANGE_ROOM_H

#include "../SpaceBar.h"
#include "../../map/Room.h"
#include "../../../view/headers/gamePage.h"

class ChangeRoom : public SpaceBar{
private:
    Room* nextRoom;
public:
    ChangeRoom(Hero* currHero, Room* room): SpaceBar(currHero){
        nextRoom = room;
        message = setMessage();
    }

    Room* getRoom(){
        return nextRoom;
    }

    COORD checkCoordinate(Room* room, Room* prevRoom){
        for(Connection* conn : room->getConn()){
            if(conn->room == prevRoom){
                return conn->door;
            }
        }
        return {0,0};
    }

    int action() override {
        COORD nextCoord = checkCoordinate(nextRoom, currHero->getCurrRoom());
        Room* prevRoom = currHero->getCurrRoom();
        currHero->setCurrRoom(nextRoom);
        nextRoom = prevRoom;
        currHero->setPos(nextCoord);
        message = setMessage();
        return GamePage::CHANGE_ROOM;
    }

    std::string setMessage(){
        return "Press Space to go to " + nextRoom->getName();
    }
};

#endif