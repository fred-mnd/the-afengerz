#ifndef TIMELINE_H
#define TIMELINE_H

#include <time.h>
#include <stdlib.h>
#include "../heroes/Hero.h"

struct TimeNode{
    clock_t endTime;
    Hero* hero;
    TimeNode* next;
};

class Timeline{
private:
    TimeNode *head, *tail;
public:
    Timeline(){
        head = NULL;
        tail = NULL;
    }

    TimeNode* createNode(clock_t endTime, Hero* hero){
        TimeNode* newNode = (TimeNode*)malloc(sizeof(TimeNode));
        newNode->endTime = endTime;
        newNode->hero = hero;
        newNode->next = NULL;

        return newNode;
    }

    void pushMid(clock_t endTime, Hero* hero){
        TimeNode* newNode = createNode(endTime, hero);
        if(!head && !tail) head = tail = newNode;
        else if(endTime <= head->endTime){
            newNode->next = head;
            head = newNode;
        }
        else if(endTime >= tail->endTime){
            tail->next = newNode;
            tail = newNode;
        }
        else{
            TimeNode* curr = head;
            while(curr && endTime < curr->endTime){
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    Hero* popHead(){
        Hero* hero = head->hero;
        if(head == tail){
            free(head);
            head = tail = NULL;
        }
        else{
            TimeNode* next = head->next;
            head->next = NULL;
            free(head);
            head = next;
        }
        return hero;
    }
};

#endif