#ifndef UPGRADE_CPP
#define UPGRADE_CPP

#include "Upgrade.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../headers/gameController.h"
#include "../../../../view/headers/upgradePage.h"
#include "../../../../model/map/Room.h"
#include <vector>

UpgradeAct::UpgradeAct() : Activities(){
    prompt = "Press Space to repair equipment";
    fail = "Someone is repairing their equipment";
    durations[0] = 30;
    durations[1] = 75;
    durations[2] = 150;
    room = RoomNS::getRoom(RoomNS::WORKSHOP);
    pos = {10, 10};
}

UpgradeAct::UpgradeAct(COORD pos, Room* room) : UpgradeAct(){
    this->room = room;
    this->pos = pos;
}

bool UpgradeAct::action(){
    if(checkEligibility(GameController::getCurrHero())){
        UpgradePage::show();
        return true;
    }
    else{
        message = "Your health is currently full";
    }
    return false;
}

int UpgradeAct::start(int options){
    duration = durations[options];
}

void UpgradeAct::end(Hero* hero, int change){
    hero->resetEquipmentHealth();
}

bool UpgradeAct::checkEligibility(Hero* hero){
    return !hero->getAct() && hero->getEqHealth() < 100 &&
    (RoomNS::getRoom(RoomNS::WORKSHOP)->getHeroList().size() == 0 ||
    (hero == HeroNS::getHero(HeroNS::IRON_MAN) && hero->getCurrRoom() == hero->getBedroom()));
}

#endif