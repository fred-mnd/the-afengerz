#ifndef SPACEBAR_H
#define SPACEBAR_H

#include <string>

class SpaceBar{
protected:
    std::string message, prompt, fail;
public:
    SpaceBar(){
    }
    std::string getMessage(){
        return this->message;
    }

    virtual bool action(){

    }

    void setPrompt(){
        message = prompt;
    }

    void setFail(){
        message = fail;
    }

    virtual ~SpaceBar(){}
};

#endif