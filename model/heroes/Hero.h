#ifndef HERO_H
#define HERO_H

#include <vector>
#include "../map/Room.h"
#include "../spacebar/actions/activities/Sleep.h"
#include <string>
#include <windows.h>

class Hero {
private:
    int health;
    int hunger;
    int level;

    Room *bedroom;
    Room* currRoom;

    char character;
    int color;

    COORD pos;
public:
    Hero(std::string filename, char character, int color){
        health = 100;
        hunger = 100;
        level = 1;
        bedroom = new Room(filename, "Bedroom");
        bedroom->addRelationship(17, 14, RoomNS::getRoom(RoomNS::LIVING_ROOM));
        currRoom = bedroom;

        this->character = character;
        this->color = color;

        pos = {10, 10};

        bedroom->addFeatures({0,0}, {7,7}, new SleepAct());
    }

    int getHealth() const{
        return health;
    }

    void setHealth(int newHealth){
        health = newHealth;
    }

    int getHunger() const{
        return hunger;
    }

    void setHunger(int newHunger){
        hunger = newHunger;
    }

    Room* getBedroom() const{
        return bedroom;
    }

    Room* getCurrRoom() const{
        return currRoom;
    }

    void setCurrRoom(Room* room){
        currRoom = room;
    }

    COORD getPos(){
        return pos;
    }

    void setPos(COORD newPos){
        pos = newPos;
    }

    char getChar(){
        return character;
    }

    int getColor(){
        return color;
    }
};

namespace HeroNS{
    enum heroName {
        BLACK_WIDOW,
        CAPTAIN_AMERICA,
        HAWKEYE,
        HULK,
        IRON_MAN,
        THOR
    };
    Hero* getHero(int index);
    void init();
}

#endif