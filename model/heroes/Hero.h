#ifndef HERO_H
#define HERO_H

#include <vector>
#include <string>
#include <windows.h>
#include <array>

class Room;
class Activities;

class Hero {
private:
    int health;
    int maxHealth;

    int hunger;
    int maxHunger;

    int level;

    Room *bedroom;
    Room* currRoom;

    char character;
    int color;
    std::string fullName;

    COORD pos;

    Activities* currAct;

    int xp;
    int maxXp;

    int equipmentHealth;

public:

    Hero(std::string filename, char character, int color, std::string fullName);

    int getHealth();

    void setHealth(int newHealth);

    int getHunger();

    void setHunger(int newHunger);

    Room* getBedroom();

    Room* getCurrRoom();

    void setCurrRoom(Room* room);

    COORD getPos();

    void setPos(COORD newPos);

    char getChar();

    int getColor();

    void setAct(Activities* act);

    Activities* getAct();

    int getXP();

    void setXP(int xp);

    void resetEquipmentHealth();

    void decreaseEquipmentHealth(int number);

    int getEqHealth();

    std::string getName();
};

namespace HeroNS{
    enum heroName {
        BLACK_WIDOW,
        CAPTAIN_AMERICA,
        HAWKEYE,
        HULK,
        IRON_MAN,
        THOR
    };
    Hero* getHero(int index);
    void init();
}

#endif