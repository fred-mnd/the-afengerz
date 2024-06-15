#ifndef HERO_CPP
#define HERO_CPP

#include "Hero.h"
#include "../map/Room.h"
#include "../../controller/spacebar/actions/Activities.h"
#include "../../etc/globals.h"
#include "../../controller/spacebar/actions/activities/Sleep.h"
#include "../../controller/spacebar/actions/activities/Training.h"
#include "../../controller/spacebar/actions/activities/Upgrade.h"

Hero::Hero(std::string filename, char character, int color, std::string fullName){
    health = 75;
    hunger = 75;
    level = 1;
    bedroom = new Room(filename, "Bedroom");
    bedroom->addRelationship(17, 14, RoomNS::getRoom(RoomNS::LIVING_ROOM));
    currRoom = bedroom;

    this->character = character;
    this->color = color;
    this->fullName = fullName;

    pos = {15, 8};

    currAct = NULL;

    xp = 0;

    equipmentHealth = 75;
}

int Hero::getHealth(){
    return health;
}

void Hero::setHealth(int newHealth){
    health += newHealth;
    if(health > maxHealth[level]) health = maxHealth[level];
}

int Hero::getHunger(){
    return hunger;
}

void Hero::setHunger(int newHunger){
    hunger += newHunger;
    if(hunger > maxHunger[level]) hunger = maxHunger[level];
}

int Hero::getMaxHealth(){
    return maxHealth[level];
}

int Hero::getMaxHunger(){
    return maxHunger[level];
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

void Hero::setAct(TimeNode* act){
    this->currAct = act;
}

TimeNode* Hero::getAct(){
    return currAct;
}

int Hero::getXP(){
    return xp;
}

void Hero::setXP(int xp){
    this->xp += xp;
    if(this->xp >= maxXp[level]) this->xp = maxXp[level];
}

int Hero::getMaxXP(){
    return maxXp[level];
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

std::string Hero::getName(){
    return fullName;
}

void Hero::levelUp(){
    level++;
    xp = 0;
}

namespace HeroNS{
    std::array<Hero*, 6> heroes;

    Hero* getHero(int index){
        return heroes[index];
    }

    void init(){
        heroes[0] = new Hero("black-widow", 'B', Globals::WHITE, "Black Widow");
        heroes[0]->getBedroom()->addFeatures({0,0}, {7,7}, new SleepAct(heroes[0]->getBedroom()));

        heroes[1] = new Hero("captain-america", 'C', Globals::BLUE, "Captain America");
        heroes[1]->getBedroom()->addFeatures({0,0}, {7,7}, new SleepAct(heroes[1]->getBedroom()));

        heroes[2] = new Hero("hawkeye", 'K', Globals::PURPLE, "Hawkeye");
        heroes[2]->getBedroom()->addFeatures({0,0}, {7,7}, new SleepAct(heroes[2]->getBedroom()));

        heroes[3] = new Hero("hulk", 'H', Globals::GREEN, "Hulk");
        heroes[3]->getBedroom()->addFeatures({0,0}, {12,10}, new SleepAct(heroes[3]->getBedroom()));

        heroes[4] = new Hero("iron-man", 'I', Globals::RED, "Iron Man");
        heroes[4]->getBedroom()->addFeatures({0,0}, {7,7}, new SleepAct(heroes[4]->getBedroom()));
        heroes[4]->getBedroom()->addFeatures({22,1}, {28,8}, new UpgradeAct({25, 1}, heroes[4]->getBedroom()));

        heroes[5] = new Hero("thor", 'T', Globals::GRAY, "Thor");
        heroes[5]->getBedroom()->addFeatures({0,0}, {7,7}, new SleepAct(heroes[5]->getBedroom()));
    }
}


#endif