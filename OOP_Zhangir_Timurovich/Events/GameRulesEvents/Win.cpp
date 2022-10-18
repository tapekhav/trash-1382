#include <iostream>
#include "Win.h"

bool Win::execute() {
    if (player && player->get_coins() > 30) {
        return true;
    }
    return false;
}

Win::Win(Player *player) : player(player) {}
