#ifndef SPACEBAR_H
#define SPACEBAR_H

#include <string>
#include "../heroes/Hero.h"

class SpaceBar{
protected:
    Hero* currHero;
    std::string message;
public:
    SpaceBar(Hero* currHero){
        this->currHero = currHero;
    }
    std::string getMessage(){
        return this->message;
    }

    virtual int action(){

    }

    virtual ~SpaceBar(){}
};

#endif