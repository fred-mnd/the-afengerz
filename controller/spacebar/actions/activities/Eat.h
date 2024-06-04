#ifndef EAT_H
#define EAT_H

#include "../Activities.h"

class EatAct : public Activities{
private:
    static COORD posList[4];
    static bool roomOcc[4];
    int posIdx;
    int addHP[3] = {20, 50, 95};
    int HP;
public:
    EatAct();

    void action();

    void start(int options);

    void end(Hero* hero);
};

#endif