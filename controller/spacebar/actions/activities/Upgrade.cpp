#ifndef UPGRADE_CPP
#define UPGRADE_CPP

#include "Upgrade.h"
#include "../../../../model/heroes/Hero.h"
#include "../../../headers/gameController.h"
#include "../../../../view/headers/upgradePage.h"
#include "../../../../model/map/Room.h"

UpgradeAct::UpgradeAct() : Activities(){
    message = "Press Space to repair equipment";
    duration[0] = 30;
    duration[1] = 75;
    duration[2] = 150;
    room = RoomNS::getRoom(RoomNS::WORKSHOP);
    pos = {10, 10};
}

UpgradeAct::UpgradeAct(COORD pos, Room* room) : Activities(){
    message = "Press Space to repair equipment";
    duration[0] = 30;
    duration[1] = 75;
    duration[2] = 150;
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

void UpgradeAct::start(int options){

}

void UpgradeAct::end(Hero* hero){
    hero->resetEquipmentHealth();
}

bool UpgradeAct::checkEligibility(Hero* hero){
    return hero->getEqHealth() < 100;
}

#endif