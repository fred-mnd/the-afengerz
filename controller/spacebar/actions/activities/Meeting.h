#ifndef MEETING_H
#define MEETING_H

#include "../Activities.h"

class MeetingAct : public Activities{
private:
    static COORD poses[6];
public:
    MeetingAct();

    bool action();

    int start(int options);

    void end(Hero* hero, int change);

    bool checkEligibility(Hero* hero);
};

#endif