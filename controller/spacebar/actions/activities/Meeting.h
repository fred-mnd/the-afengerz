#ifndef MEETING_H
#define MEETING_H

#include "../Activities.h"

class MeetingAct : public Activities{
public:
    MeetingAct();

    bool action();

    void start(int options);

    void end(Hero* hero);

    bool checkEligibility(Hero* hero);
};

#endif