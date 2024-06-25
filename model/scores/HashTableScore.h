#ifndef HASH_TABLE_SCORE_H
#define HASH_TABLE_SCORE_H

#include "ScoreStruct.h"

class HashTableScore{
private:
    ScoreNode *head[26], *tail[26];

public:
    HashTableScore(){
        for(int i = 0; i < 26; i++){
            head[i] = NULL;
            tail[i] = NULL;
        }
    }

    int hash(std::string name){
        if(name[0] >= 'A' && name[0] <= 'Z'){
            return name[0] - 'A';
        }
        else{
            return name[0] - 'a';
        }
    }

    void insert(ScoreNode* node){
        int idx = hash(node->name);
        if(!head[idx]){
            head[idx] = tail[idx] = node;
        }
        else{
            tail[idx]->hnext = node;
            tail[idx] = node;
        }
    }

    void print(){
        for(int i = 0; i < 26; i++){
            ScoreNode* temp = head[i];
            while(temp){
                // print
                temp = temp->hnext;
            }
        }
    }
};

#endif