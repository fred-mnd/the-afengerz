#ifndef ACTIVITIES_H
#define ACTIVITIES_H

class Hero;
class Room;

#include "../SpaceBar.h"
#include <windows.h>

class Activities : public SpaceBar{
protected:
    COORD pos;
    Room* room;
public:
    Activities() : SpaceBar(){

    }

    virtual void action(){
        
    }

    virtual void start(int options){
        
    }

    virtual void end(Hero* hero){
        
    }

    virtual void start(){

    }

    virtual ~Activities(){

    }

    COORD getPos(){
        return pos;
    }
    
    void setPos(COORD pos){
        this->pos = pos;
    }

    Room* getRoom(){
        return room;
    }
};

#endif