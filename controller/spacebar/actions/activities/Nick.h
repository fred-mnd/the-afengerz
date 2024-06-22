#ifndef NICK_H
#define NICK_H

#include "../Activities.h"

class NickAct : public Activities{
public:
    NickAct();

    bool action();

    int start(int options);

    void end(Hero* hero, int change);

    int checkEligibility(Hero* hero);
};

#endif