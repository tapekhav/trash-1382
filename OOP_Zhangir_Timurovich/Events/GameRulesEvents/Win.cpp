#include <iostream>
#include "Win.h"

bool Win::execute() {
    if (player && player->get_coins() > 30) {
        Message message(GAME, "Event happened");
        notify(message);
        return true;
    }
    return false;
}

Win::Win(Player *player){
    this->player = player;
}

