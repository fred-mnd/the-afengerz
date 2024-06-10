#ifndef UPGRADE_H
#define UPGRADE_H

#include "../Activities.h"

class UpgradeAct : public Activities{
public:
    UpgradeAct();
    UpgradeAct(COORD pos, Room* room);

    bool action();

    void start(int options);

    void end(Hero* hero);

    bool checkEligibility(Hero* hero);
};

#endif