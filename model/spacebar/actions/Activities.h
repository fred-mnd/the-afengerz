#ifndef ACTIVITIES_H
#define ACTIVITIES_H

#include "../SpaceBar.h"

class Activities : public SpaceBar{
public:
    Activities(Hero* currHero) : SpaceBar(currHero){

    }

    virtual void start(){
        
    }

    virtual ~Activities(){

    }
};

#endif