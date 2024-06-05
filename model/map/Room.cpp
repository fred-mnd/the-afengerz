#ifndef ROOM_CPP
#define ROOM_CPP

#include "Room.h"
#include "../../controller/spacebar/actions/activities/Training.h"
#include "../../controller/spacebar/actions/activities/Upgrade.h"
#include "../../controller/spacebar/actions/activities/Eat.h"
#include "../../controller/spacebar/actions/Activities.h"

Features::Features(COORD start, COORD end, Activities* act){
    this->start = start;
    this->end = end;
    this->act = act;
}
bool Features::checkNear(COORD pos){
    return (pos.X >= start.X && pos.X <= end.X && pos.Y >= start.Y && pos.Y <= end.Y);
}

Activities* Features::getAct(){
    return act;
}

Connection::Connection(short x, short y, Room* next){
    door = {x, y};
    this->room = next;
}

Room::Room(std::string filename, std::string name){
    char path[100];
    sprintf(path, "model/map/map-assets/%s.txt", filename.c_str());
    FILE* import = fopen(path, "r");
    char scanned[40];
    for(int i=0; fscanf(import, "%[^\n]\n", scanned) != -1;i++){
        map[i][30] = 0;
        for(int j=0;j<31;j++){
            map[i][j] = scanned[j];
        }
    }
    this->name = name;
}

void Room::addFeatures(COORD start, COORD end, Activities* act){
    featList.push_back(new Features(start, end, act));
}

void Room::addRelationship(int x, int y, Room* nextRoom){
    connList.push_back(new Connection(x, y, nextRoom));
}

void Room::changeRelationship(std::vector<Connection*>::size_type idx, Room* nextRoom){
    connList[idx]->room = nextRoom;
}

std::array<std::array<char, 31>, 15> Room::getMap(){
    return this->map;
}

std::vector<class Connection*> Room::getConn(){
    return connList;
}

std::string Room::getName(){
    return name;
}

std::vector<Features*> Room::getFeat(){
    return featList;
}

std::vector<Hero*> Room::getHeroList(){
    return heroList;
}

void Room::addHero(Hero* hero){
    heroList.push_back(hero);
}

void Room::removeHero(Hero* hero){
    std::vector<Hero*>::iterator it = std::find(heroList.begin(), heroList.end(), hero);
    if(it == heroList.end()) return;
    heroList.erase(it);
}


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
        rooms[RoomNS::RESTAURANT]->addFeatures({27, 12}, {27, 12}, new EatAct());

    }
}

#endif