#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <iostream>
#include <string>

class Connection;
class Room;

class Room{
private:
    char map[15][40];
    std::vector<class Connection*> connList;
public:
    Room(std::string filename){
        char path[100];
        sprintf(path, "model/map/map-assets/%s.txt", filename);
        FILE* import = fopen(path, "r");
        char scanned[50];
        for(int i=0; fscanf(import, "%[^\n]\n", scanned) != -1;i++){
            printf("%s\n", scanned);
        }
    }

    void addRelationship(int x, int y, Room* nextRoom){
        connList.push_back(new Connection(x, y, nextRoom));
    }
};

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

enum roomName{
    LIVING_ROOM,
    WORKSHOP_ROOM,
    TRAINING_ROOM,
    TRAINING_ROOM,
    MEETING_ROOM,
    RESTAURANT
};

namespace RoomNS{
    Room* getRoom(int index);
    void init();
}

#endif