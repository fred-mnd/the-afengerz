#ifndef TIMELINE_CPP
#define TIMELINE_CPP

#include "Timeline.h"
#include "../../controller/spacebar/actions/Activities.h"
#include "../map/Room.h"

TimeNode* Timeline::createNode(clock_t endTime, Hero* hero, Activities* act){
    TimeNode* newNode = (TimeNode*)malloc(sizeof(TimeNode));
    newNode->endTime = endTime;
    newNode->hero = hero;
    newNode->act = act;
    newNode->next = newNode->prev = NULL;

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
        head->prev = newNode;
        head = newNode;
    }
    else if(endTime >= tail->endTime){
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else{
        TimeNode* curr = head;
        while(curr && endTime < curr->endTime){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next->prev = newNode;
        curr->next = newNode;
        newNode->prev = curr;
    }

    newNode->pos = act->getPos();

    return newNode;
}

Activities* Timeline::popHead(){
    Hero* hero = head->hero;
    int change = head->change;
    if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        TimeNode* next = head->next;
        head->next = NULL;
        free(head);
        head = next;
        next->prev = NULL;
    }
    Activities* act = hero->getAct()->act;
    act->end(hero, change);
    act->getRoom()->removeHero(hero);
    hero->setAct(NULL);
    return act;
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