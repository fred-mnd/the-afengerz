#ifndef TRAINING_H
#define TRAINING_H

#include "../Activities.h"

class TrainingAct : public Activities{
private:
    int XP;
    int XPList[3] = {20, 35, 50};
public:
    TrainingAct();

    void action();

    void start(int options);

    void end(Hero* hero);
};

#endif