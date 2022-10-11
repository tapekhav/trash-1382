#include "Heal.h"

void Heal::execute(void *obj) {
    auto* player = (Player*) obj;
    if (player) {
        if (player->is_max_health()) {
            player->set_damage(player->get_damage() + 1);
        } else
            player->set_health(player->get_health() + 1);
    }
}
