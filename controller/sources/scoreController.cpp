#ifndef SCORE_CONTROLLER_CPP
#define SCORE_CONTROLLER_CPP

#include "../headers/scoreController.h"
#include "../../model/scores/ScoreStruct.h"
#include "../../model/scores/HashTableScore.h"
#include "../../model/scores/LinkedListScore.h"


namespace ScoreController{
    LinkedListScore* lls = new LinkedListScore();
    HashTableScore* hts = new HashTableScore();

    void insertData(std::string name, int score){
        ScoreNode* node = ScoreNS::createNode(name, score);
        hts->insert(node);
        lls->pushMid(node);
    }
    void init(){
        FILE* fp = fopen("scores/score.txt", "r");
        if(fp == NULL){
            printf("Error opening file\n");
            return;
        }
        char name[256];
        int score;
        for(;fscanf(fp, "%[^`]`%d\n", name, score) != -1;){
            insertData(name, score);
        }
    }

    void writeData(std::string name, int score){
        FILE* fp = fopen("scores/score.txt", "a");
        fprintf(fp, "%s`%d\n", name.c_str(), score);
    }
} 

#endif