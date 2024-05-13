#ifndef SPACEBAR_H
#define SPACEBAR_H

#include <string>

class SpaceBar{
private:
    std::string message;
public:
    SpaceBar(std::string message){
        this->message = message;
    }
    std::string getMessage(){
        return this->message;
    }

    virtual ~SpaceBar(){}
};

#endif