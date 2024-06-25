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
    
    durations[0] = 30;
    durations[1] = 75;
    durations[2] = 150;
    room = RoomNS::getRoom(RoomNS::WORKSHOP);
    pos = {10, 10};
    status = "Repairing";
}

UpgradeAct::UpgradeAct(COORD pos, Room* room) : UpgradeAct(){
    this->room = room;
    this->pos = pos;
}

bool UpgradeAct::action(){
    int elig = checkEligibility(GameController::getCurrHero());
    if(elig == 0){
        UpgradePage::show();
        return true;
    }
    else if(elig == 1){
        fail = "You're not idle";
    }
    else if(elig == 2){
        fail = "Your equipment is in prime condition";
    }
    else if(elig == 3){
        fail = "Someone is repairing their equipment";
    }
    setFail();
    return false;
}

int UpgradeAct::start(int options){
    duration = durations[options];
    score = 40;
    return -1;
}

void UpgradeAct::end(Hero* hero, int change){
    hero->resetEquipmentHealth();
}

int UpgradeAct::checkEligibility(Hero* hero){
    if(hero->getAct()) return 1;
    if(hero->getEqHealth() >= 100) return 2;
    if(!(RoomNS::getRoom(RoomNS::WORKSHOP)->getHeroList().size() == 0 ||
    (hero == HeroNS::getHero(HeroNS::IRON_MAN) && hero->getCurrRoom() == hero->getBedroom()))) return 3;

    return 0;
}

#endif