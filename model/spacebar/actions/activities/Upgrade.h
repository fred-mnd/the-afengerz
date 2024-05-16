#ifndef UPGRADE_H
#define UPGRADE_H

#include "../Activities.h"

class UpgradeAct : public Activities{
public:
    UpgradeAct() : Activities(){
        message = "Press Space to upgrade equipment";
    }
};

#endif