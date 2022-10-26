
#include <iostream>
#include "Lose.h"

bool Lose::execute() {
    if (this->player && this->player->get_health() <= 0) {
        notify();
        return true;
    }
    return false;
}

Lose::Lose(Player *player) {
    this->player = player;
};

