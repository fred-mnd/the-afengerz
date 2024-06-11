#ifndef TIMELINE_CPP
#define TIMELINE_CPP

#include "Timeline.h"
#include "../../controller/spacebar/actions/Activities.h"

TimeNode* Timeline::createNode(clock_t endTime, Hero* hero, Activities* act){
    TimeNode* newNode = (TimeNode*)malloc(sizeof(TimeNode));
    newNode->endTime = endTime;
    newNode->hero = hero;
    newNode->act = act;
    newNode->next = NULL;

    return newNode;
}

Timeline::Timeline(){
    head = NULL;
    tail = NULL;
}

TimeNode* Timeline::pushMid(clock_t endTime, Hero* hero, Activities* act){
    printf("augh");
    TimeNode* newNode = createNode(endTime, hero, act);
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

    newNode->pos = act->getPos();

    return newNode;
}

Hero* Timeline::popHead(){
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

void Timeline::view(){
    TimeNode* curr = head;
    while(curr){
        printf("Name = %c\n", curr->hero->getChar());
        printf("Act = %s\n", curr->hero->getAct()->act->getMessage().c_str());
        printf("End Time = %ld", curr->endTime);
        curr = curr->next;
    }
}

clock_t Timeline::getHeadTime(){
    return head->endTime;
}

bool Timeline::isHead(){
    return head;
}

#endif