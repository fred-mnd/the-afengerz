#ifndef SPACEBAR_H
#define SPACEBAR_H

#include <string>

class SpaceBar{
protected:
    std::string message;
public:
    SpaceBar(){
    }
    std::string getMessage(){
        return this->message;
    }

    virtual int action(){

    }

    virtual ~SpaceBar(){}
};

#endif