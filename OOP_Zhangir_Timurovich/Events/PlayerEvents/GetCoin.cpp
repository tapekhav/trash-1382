#include "GetCoin.h"

bool GetCoin::execute(void *obj) {
    if (obj) {
        auto *player = (Player *) obj;
        player->set_coins(player->get_coins() + 1);
        return true;
    }
    return false;
}

