#include "GetCoin.h"

void GetCoin::execute(Player *player) {
    player->set_coins(player->get_coins() + 1);
}

