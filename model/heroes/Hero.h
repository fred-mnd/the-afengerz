#ifndef HERO_H
#define HERO_H

#include <vector>
#include "../map/Room.h"
#include <string>

class Hero {
private:
    int health;
    int hunger;
    int level;
    Room *bedroom;
public:
    Hero(std::string filename){
        health = 100;
        hunger = 100;
        level = 1;
        bedroom = new Room(filename);
        bedroom->addRelationship(13, 17, RoomNS::getRoom(RoomNS::LIVING_ROOM));
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