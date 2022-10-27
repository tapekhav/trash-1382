#include <iostream>
#include "Win.h"

bool Win::execute(LogOutInfo* info) {
    if (player && player->get_coins() > 30) {
        Message message(GAME, "Win event happened", info);
        notify(message);
        return true;
    }
    return false;
}

Win::Win(Player *player){
    this->player = player;
}

