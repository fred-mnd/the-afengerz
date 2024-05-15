#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <iostream>
#include <string>
#include <array>
#include <windows.h>

class Connection;
class Room;
class Activities;

class Features{
private:
    COORD start;
    COORD end;
public:
    Features(COORD start, COORD end){
        this->start = start;
        this->end = end;
    }
    bool checkNear(COORD pos){
        return (pos.X >= start.X && pos.X <= end.X && pos.Y >= start.Y && pos.Y <= end.Y);
    }
};

class Connection{
public:
    Room* room;
    COORD door;

    Connection(short x, short y, Room* next){
        door = {x, y};
        this->room = next;
    }
};

class Room{
private:
    std::array<std::array<char, 31>, 15> map;
    std::vector<class Connection*> connList;
    std::string name;
    std::vector<Features*> featList;
public:
    Room(std::string filename, std::string name){
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
    
    void addFeatures(COORD start, COORD end){
        
    }

    void addRelationship(int x, int y, Room* nextRoom){
        connList.push_back(new Connection(x, y, nextRoom));
    }

    void changeRelationship(std::vector<Connection*>::size_type idx, Room* nextRoom){
        connList[idx]->room = nextRoom;
    }

    std::array<std::array<char, 31>, 15> getMap(){
        return this->map;
    }

    std::vector<class Connection*> getConn(){
        return connList;
    }

    std::string getName(){
        return name;
    }
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