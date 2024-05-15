#ifndef SPACEBAR_H
#define SPACEBAR_H

class Hero;

#include <string>

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