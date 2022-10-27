#include "GetCoin.h"

bool GetCoin::execute(LogOutInfo* info) {
    if (player) {
        player->set_coins(player->get_coins() + 1);
        Message message(GAME, "Coin event happened", info);
        notify(message);
        return true;
    }
    return false;
}

GetCoin::GetCoin(Player *player) {
    this->player = player;
}

