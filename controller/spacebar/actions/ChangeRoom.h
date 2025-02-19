#ifndef CHANGE_ROOM_H
#define CHANGE_ROOM_H

#include "../SpaceBar.h"
#include "../../../model/map/Room.h"
#include "../../../model/heroes/Hero.h"

class ChangeRoom : public SpaceBar{
private:
    Hero* currHero;
    Room* nextRoom;
public:
    ChangeRoom(Hero* currHero, Room* room): SpaceBar(){
        nextRoom = room;
        message = setMessage();
        this->currHero = currHero;
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

    bool action() override {
        COORD nextCoord = checkCoordinate(nextRoom, currHero->getCurrRoom());
        Room* prevRoom = currHero->getCurrRoom();
        currHero->setCurrRoom(nextRoom);
        nextRoom = prevRoom;
        currHero->setPos(nextCoord);
        message = setMessage();
    }

    std::string setMessage(){
        return "Press Space to go to " + nextRoom->getName();
    }
};

#endif