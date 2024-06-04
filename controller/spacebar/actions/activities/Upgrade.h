#ifndef UPGRADE_H
#define UPGRADE_H

#include "../Activities.h"

class UpgradeAct : public Activities{
public:
    UpgradeAct();
    UpgradeAct(COORD pos, Room* room);

    void action();

    void start(int options);

    void end(Hero* hero);
};

#endif