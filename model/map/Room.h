#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <iostream>
#include <string>
#include <array>
#include <windows.h>
#include <algorithm>

class Connection;
class Room;
class Hero;
class Activities;

class Features{
private:
    COORD start;
    COORD end;
    Activities* act;
public:
    Features(COORD start, COORD end, Activities* act);
    bool checkNear(COORD pos);
    Activities* getAct();
};

class Connection{
public:
    Room* room;
    COORD door;

    Connection(short x, short y, Room* next);
};

class Room{
private:
    std::array<std::array<char, 31>, 15> map;
    std::vector<class Connection*> connList;
    std::string name;
    std::vector<Features*> featList;
    std::vector<Hero*> heroList;
public:
    Room(std::string filename, std::string name);
    
    void addFeatures(COORD start, COORD end, Activities* act);

    void addRelationship(int x, int y, Room* nextRoom);

    void changeRelationship(std::vector<Connection*>::size_type idx, Room* nextRoom);

    std::array<std::array<char, 31>, 15> getMap();

    std::vector<class Connection*> getConn();

    std::string getName();

    std::vector<Features*> getFeat();

    std::vector<Hero*> getHeroList();

    void addHero(Hero* hero);

    void removeHero(Hero* hero);
};

namespace RoomNS{
    enum roomName{
        LIVING_ROOM,
        MEETING_ROOM,
        TRAINING_ROOM,
        WORKSHOP,
        RESTAURANT
    };
    Room* getRoom(int index);
    void init();
}

#endif