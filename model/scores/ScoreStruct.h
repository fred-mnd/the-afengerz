#ifndef SCORE_STRUCT_H
#define SCORE_STRUCT_H

#include <string>

struct ScoreNode{
    std::string name;
    int score;
    ScoreNode *hnext;
    ScoreNode *lnext;
};

namespace ScoreNS{
    ScoreNode* createNode(std::string name, int score){
        ScoreNode* newNode = new ScoreNode;
        newNode->name = name;
        newNode->score = score;
        newNode->hnext = newNode->lnext = NULL;
        return newNode;
    }

    void print(ScoreNode* node){
        printf("%-20s | %d\n", node->name.c_str(), node->score);
    }
}

#endif