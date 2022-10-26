#include "GetCoin.h"

bool GetCoin::execute() {
    if (player) {
        player->set_coins(player->get_coins() + 1);
        Message message(GAME, "Event happened");
        notify(message);
        return true;
    }
    return false;
}

GetCoin::GetCoin(Player *player) {
    this->player = player;
}

