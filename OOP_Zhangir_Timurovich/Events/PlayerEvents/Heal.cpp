#include "Heal.h"


Heal::Heal(Player *player) {
    this->player = player;
}

bool Heal::execute() {
    if (player) {
        if (player->is_max_health()) {
            player->set_damage(player->get_damage() + 1);
        } else
            player->set_health(player->get_health() + 1);
        return true;
    }
    return false;
}
