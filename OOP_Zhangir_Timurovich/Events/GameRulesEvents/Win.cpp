#include <iostream>
#include "Win.h"

bool Win::execute() {
    if (player && player->get_coins() > 30) {
        notify();
        return true;
    }
    return false;
}

Win::Win(Player *player){
    this->player = player;
}

