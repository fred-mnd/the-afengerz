#ifndef TIMELINE_CPP
#define TIMELINE_CPP

#include "Timeline.h"
#include "../../controller/spacebar/actions/Activities.h"
#include "../../controller/headers/gameController.h"
#include "../../etc/globals.h"
#include "../map/Room.h"

TimeNode* Timeline::createNode(clock_t endTime, Hero* hero, Activities* act){
    TimeNode* newNode = (TimeNode*)malloc(sizeof(TimeNode));
    newNode->endTime = endTime;
    newNode->hero = hero;
    newNode->act = act;
    newNode->next = newNode->prev = NULL;

    return newNode;
}

MasterTime* Timeline::createNode(){
    MasterTime* newNode = (MasterTime*)malloc(sizeof(MasterTime));
    newNode->head = newNode->tail = NULL;
    newNode->prev = newNode->next = NULL;

    return newNode;
}

Timeline::Timeline(){
    head = NULL;
    tail = NULL;
}

TimeNode* Timeline::pushMid(clock_t endTime, Hero* hero, Activities* act){
    TimeNode* newNode = createNode(endTime, hero, act);
    MasterTime* node;

    if(!head && !tail){
        head = tail = createNode();
        node = head;
    }
    else if(endTime <= head->head->endTime){
        node = createNode();
        node->next = head;
        head->prev = node;
        head = node;
    }
    else if(endTime >= tail->head->endTime){
        node = createNode();
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    else{
        MasterTime* curr = head;
        while(curr && endTime > curr->head->endTime){
            curr = curr->next;
        }
        if(endTime < curr->head->endTime){
            node = createNode();
            node->prev = curr->prev;
            curr->prev->next = node;
            curr->prev = node;
            node->next = curr;
        }
        else node = curr;
    }
    
    if(!node->head) node->head = node->tail = newNode;
    else{
        node->tail->next = newNode;
        newNode->prev = node->tail;
        node->tail = newNode;
    }

    newNode->pos = act->getPos();

    return newNode;
}

Activities* Timeline::popHead(){
    TimeNode *head = this->head->head;
    TimeNode *tail = this->head->tail;
    Hero* hero = head->hero;
    Activities* act = hero->getAct()->act;
    int change = head->change;
    int score = head->score;
    if(head == tail){
        free(head);
        this->head->head = this->head->tail = NULL;
        cleanUp(this->head);
    }
    else{
        TimeNode* next = head->next;
        head->next = NULL;
        free(head);
        this->head->head = next;
        next->prev = NULL;
    }
    GameController::addScore(score);
    act->end(hero, change);
    hero->setAct(NULL);
    act->getRoom()->removeHero(hero);

    return act;
}

clock_t Timeline::getHeadTime(){
    return head->head->endTime;
}

bool Timeline::isEmpty(){
    return !head;
}

bool Timeline::isHead(){
    return head && head->head;
}

void Timeline::cleanUp(MasterTime* node){
    if(node == head){
        if(head == tail){
            free(head);
            head = tail = NULL;
        }
        else{
            MasterTime* next = head->next;
            head->next = NULL;
            free(head);
            head = next;
            head->prev = NULL;
        }
    }
    else if(node == tail){
        MasterTime* prev = tail->prev;
        tail->prev = NULL;
        free(tail);
        tail = prev;
        tail->next = NULL;


    }
    else{
        node->prev->next = node->next;
        node->next->prev = node->prev;
        free(node);
    }
}

Activities* Timeline::popMid(TimeNode* tn){
    MasterTime* curr = head;
    tn->act->getRoom()->removeHero(tn->hero);
    tn->act->forceRemove(tn->hero);
    Activities* act = tn->act;
    while(curr){
        if(!curr->head) continue;
        if(curr->head->endTime == tn->endTime) break;
        curr = curr->next;
    }

    if(tn == curr->head){
        if(curr->head == curr->tail){
            free(tn);
            curr->head = curr->tail = NULL;
            cleanUp(curr);
        }
        else{
            TimeNode* next = tn->next;
            free(tn);
            next->prev = NULL;
            curr->head = next;
        }
    }
    else if(tn == curr->tail){
        TimeNode* prev = tn->prev;
        free(tn);
        prev->next = NULL;
        curr->tail = prev;
    }
    else{
        tn->prev->next = tn->next;
        tn->next->prev = tn->prev;
        free(tn);
    }

    return act;
}

#endif