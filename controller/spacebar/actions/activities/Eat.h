#ifndef EAT_H
#define EAT_H

#include "../Activities.h"

class EatAct : public Activities{
private:
    static COORD posList[4];
    static bool roomOcc[4];
    int posIdx;
    int addHP[3] = {20, 50, 95};
public:
    EatAct();

    bool action();

    int start(int options);

    void end(Hero* hero, int change);

    bool checkEligibility(Hero* hero);
};

#endif