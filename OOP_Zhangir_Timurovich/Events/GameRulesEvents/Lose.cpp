
#include <iostream>
#include "Lose.h"

bool Lose::execute() {
    if (this->player && this->player->get_health() <= 0) {
        Message message(GAME, "Event happened");
        notify(message);
        return true;
    }
    return false;
}

Lose::Lose(Player *player) {
    this->player = player;
};

