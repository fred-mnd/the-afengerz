#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <iostream>
#include <string>
#include <cstring>

class Connection;
class Room;

class Connection{
public:
    Room* room;
    int x;
    int y;

    Connection(int x, int y, Room* next){
        this->x = x;
        this->y = y;
        this->room = next;
    }
};

class Room{
private:
    char map[15][40];
    std::vector<class Connection*> connList;
public:
    Room(std::string filename){
        char path[100];
        sprintf(path, "model/map/map-assets/%s.txt", filename.c_str());
        FILE* import = fopen(path, "r");
        char scanned[50];
        for(int i=0; fscanf(import, "%[^\n]\n", scanned) != -1;i++){
            std::strcpy(map[i], scanned);
        }
    }

    void addRelationship(int x, int y, Room* nextRoom){
        connList.push_back(new Connection(x, y, nextRoom));
    }
};


namespace RoomNS{
    enum roomName{
        LIVING_ROOM,
        WORKSHOP_ROOM,
        TRAINING_ROOM,
        MEETING_ROOM,
        RESTAURANT
    };
    Room* getRoom(int index);
    void init();
    void changeBedroom();
}

#endif