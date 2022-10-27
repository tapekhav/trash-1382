#include "Heal.h"


Heal::Heal(Player *player) {
    this->player = player;
}

bool Heal::execute(LogOutInfo* info) {
    if (player) {
        if (player->is_max_health()) {
            player->set_damage(player->get_damage() + 1);
        } else
            player->set_health(player->get_health() + 1);
        Message message(GAME, "Heal event happened", info);
        notify(message);
        return true;
    }
    return false;
}

