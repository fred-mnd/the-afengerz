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
    int durations[3];
    int duration;
    int score;
    std::string status;
public:
    Activities() : SpaceBar(){

    }

    int getDuration(){
        return duration;
    }

    int getScore(){
        return score;
    }

    int getDurationFromArray(int options){
        return durations[options];
    }

    virtual bool action(){

    }

    virtual int start(int options){
        
    }

    virtual void end(Hero* hero, int change){
    
    }

    virtual ~Activities(){

    }

    virtual void forceRemove(Hero* hero){
        
    }

    virtual int checkEligibility(Hero* hero){

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

    std::string getStatus(){
        return status;
    }
};

#endif