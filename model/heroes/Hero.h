#ifndef HERO_H
#define HERO_H

#include <vector>
#include <string>
#include <windows.h>
#include <array>

class Room;
class TimeNode;

class Hero {
private:
    int health;
    int maxHealth[6] = {0, 100, 150, 200, 300, 500};

    int hunger;
    int maxHunger[6] = {0, 100, 150, 200, 250, 300};

    int level;

    Room *bedroom;
    Room* currRoom;

    char character;
    int color;
    std::string fullName;

    COORD pos;

    TimeNode* currAct;

    int xp;
    int maxXp[6] = {0, 100, 200, 350, 500, 1000};

    int equipmentHealth;

public:

    Hero(std::string filename, char character, int color, std::string fullName);

    int getHealth();

    void setHealth(int newHealth);

    int getHunger();

    void setHunger(int newHunger);

    int getMaxHealth();

    int getMaxHunger();

    Room* getBedroom();

    Room* getCurrRoom();

    void setCurrRoom(Room* room);

    COORD getPos();

    void setPos(COORD newPos);

    char getChar();

    int getColor();

    void setAct(TimeNode* act);

    TimeNode* getAct();

    int getXP();

    void setXP(int xp);

    int getMaxXP();

    void resetEquipmentHealth();

    void decreaseEquipmentHealth(int number);

    int getEqHealth();

    void levelUp();

    std::string getName();

    std::string getStatus();

    int getLevel();
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