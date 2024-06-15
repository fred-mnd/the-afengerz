#ifndef TRAINING_H
#define TRAINING_H

#include "../Activities.h"

class TrainingAct : public Activities{
private:
    int XPList[3] = {20, 35, 50};
public:
    TrainingAct();

    bool action();

    int start(int options);

    void end(Hero* hero, int change);

    bool checkEligibility(Hero* hero);

};

#endif