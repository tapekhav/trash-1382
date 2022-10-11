#include "GetCoin.h"

void GetCoin::execute(void *obj) {
    auto* player = (Player*) obj;
    if (player) {
        player->set_coins(player->get_coins() + 1);
    }
}

