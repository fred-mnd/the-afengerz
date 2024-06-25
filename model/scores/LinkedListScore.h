#ifndef LINKED_LIST_SCORE_H
#define LINKED_LIST_SCORE_H

#include "ScoreStruct.h"

class LinkedListScore{
private:
    ScoreNode *head, *tail;

public:
    LinkedListScore(){
        head = tail = NULL;
    }

    void pushMid(ScoreNode* node){
        if(!head) head = tail = node;
        else if(node->score >= head->score){
            node->lnext = head;
            head = node;
        }
        else if(node->score <= tail->score){
            tail->lnext = node;
            tail = node;
        }
        else{
            ScoreNode* temp = head;
            while(node->score < temp->lnext->score){
                temp = temp->lnext;
            }
            node->lnext = temp->lnext;
            temp->lnext = node;
        }
    }

    void print(){
        ScoreNode* temp = head;
        while(temp){
            // print hereee
            temp = temp->lnext;
        }
    }
};

#endif