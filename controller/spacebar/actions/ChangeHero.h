#ifndef CHANGE_HERO_H
#define CHANGE_HERO_H

#include "../SpaceBar.h"
#include "../../../model/heroes/Hero.h"
#include "../../../view/headers/changeHeroPage.h"

class ChangeHero : public SpaceBar{
protected:
    int currHero;
public:
    ChangeHero() : SpaceBar(){
        message = "Press Space to switch avenger";
    }

    void action(){
        ChangeHeroPage::show();
    }


};

#endif