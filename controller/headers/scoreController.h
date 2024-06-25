#ifndef SCORE_CONTROLLER_H
#define SCORE_CONTROLLER_H

#include <string>

struct ScoreNode;

namespace ScoreController{
    void insertData(std::string name, int score);
    void init();
    void writeData(std::string name, int score);
    void view(bool options);
} 


#endif