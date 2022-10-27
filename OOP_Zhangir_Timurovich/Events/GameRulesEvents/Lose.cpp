
#include <iostream>
#include "Lose.h"

bool Lose::execute(LogOutInfo* info) {
    if (this->player && this->player->get_health() <= 0) {
        Message message(GAME, "Lose event happened", info);
        notify(message);
        return true;
    }
    return false;
}

Lose::Lose(Player *player) {
    this->player = player;
};

