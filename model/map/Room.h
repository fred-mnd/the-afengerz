#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <iostream>
#include <string>
#include <array>

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
    std::array<std::array<char, 31>, 15> map;
    std::vector<class Connection*> connList;
public:
    Room(std::string filename){
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