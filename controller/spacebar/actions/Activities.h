#ifndef ACTIVITIES_H
#define ACTIVITIES_H

#include "../SpaceBar.h"
// #include "../../../model/heroes/Hero.h"
#include <windows.h>

class Activities : public SpaceBar{
protected:
    COORD pos;

public:
    Activities() : SpaceBar(){

    }

    virtual void action(){
        
    }

    virtual void start(int options){
        
    }

    virtual void end(){
        
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
};

#endif