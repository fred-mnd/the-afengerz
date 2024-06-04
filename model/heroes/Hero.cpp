#ifndef HERO_CPP
#define HERO_CPP

#include "Hero.h"
#include "../map/Room.h"
#include "../../controller/spacebar/actions/Activities.h"
#include "../../etc/globals.h"
#include "../../controller/spacebar/actions/activities/Sleep.h"
#include "../../controller/spacebar/actions/activities/Training.h"
#include "../../controller/spacebar/actions/activities/Upgrade.h"

Hero::Hero(std::string filename, char character, int color){
    health = 100;
    maxHealth = 100;
    hunger = 100;
    maxHunger = 100;
    level = 1;
    bedroom = new Room(filename, "Bedroom");
    bedroom->addRelationship(17, 14, RoomNS::getRoom(RoomNS::LIVING_ROOM));
    currRoom = bedroom;

    this->character = character;
    this->color = color;

    pos = {15, 8};

    currAct = NULL;

    xp = 0;
    int maxXP = 100;

    equipmentHealth = 100;
}

int Hero::getHealth(){
    return health;
}

void Hero::setHealth(int newHealth){
    health += newHealth;
    if(health > maxHealth) health = maxHealth;
}

int Hero::getHunger(){
    return hunger;
}

void Hero::setHunger(int newHunger){
    hunger += newHunger;
    if(hunger > maxHunger) hunger = maxHunger;
}

Room* Hero::getBedroom(){
    return bedroom;
}

Room* Hero::getCurrRoom(){
    return currRoom;
}

void Hero::setCurrRoom(Room* room){
    currRoom = room;
}

COORD Hero::getPos(){
    return pos;
}

void Hero::setPos(COORD newPos){
    pos = newPos;
}

char Hero::getChar(){
    return character;
}

int Hero::getColor(){
    return color;
}

void Hero::setAct(Activities* act){
    this->currAct = act;
}

Activities* Hero::getAct(){
    return currAct;
}

int Hero::getXP(){
    return xp;
}

void Hero::setXP(int xp){
    this->xp += xp;
    if(this->xp >= maxXp) this->xp = maxXp;
}

void Hero::resetEquipmentHealth(){
    equipmentHealth = 100;
}

void Hero::decreaseEquipmentHealth(int number){
    equipmentHealth -= number;
}

int Hero::getEqHealth(){
    return equipmentHealth;
}

namespace HeroNS{
    std::array<Hero*, 6> heroes;

    Hero* getHero(int index){
        return heroes[index];
    }

    void init(){
        heroes[0] = new Hero("black-widow", 'B', Globals::WHITE);
        heroes[0]->getBedroom()->addFeatures({0,0}, {7,7}, new SleepAct(heroes[0]->getBedroom()));

        heroes[1] = new Hero("captain-america", 'C', Globals::BLUE);
        heroes[1]->getBedroom()->addFeatures({0,0}, {7,7}, new SleepAct(heroes[1]->getBedroom()));

        heroes[2] = new Hero("hawkeye", 'K', Globals::PURPLE);
        heroes[2]->getBedroom()->addFeatures({0,0}, {7,7}, new SleepAct(heroes[2]->getBedroom()));

        heroes[3] = new Hero("hulk", 'H', Globals::GREEN);
        heroes[3]->getBedroom()->addFeatures({0,0}, {12,10}, new SleepAct(heroes[3]->getBedroom()));

        heroes[4] = new Hero("iron-man", 'I', Globals::RED);
        heroes[4]->getBedroom()->addFeatures({0,0}, {7,7}, new SleepAct(heroes[4]->getBedroom()));
        heroes[4]->getBedroom()->addFeatures({22,1}, {28,8}, new UpgradeAct({25, 1}, heroes[4]->getBedroom()));

        heroes[5] = new Hero("thor", 'T', Globals::GRAY);
        heroes[5]->getBedroom()->addFeatures({0,0}, {7,7}, new SleepAct(heroes[5]->getBedroom()));
    }
}


#endif