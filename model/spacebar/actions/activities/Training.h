#ifndef TRAINING_H
#define TRAINING_H

#include "../Activities.h"

class TrainingAct : public Activities{
public:
    TrainingAct() : Activities(){
        message = "Press Space to start training";
    }
};

#endif