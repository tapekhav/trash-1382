#include "Heal.h"

void Heal::execute(Player *player) {
    if (player->is_max_health()){
        player->set_damage(player->get_damage() + 1);
    }
    else
        player->set_health(player->get_health() + 1);
}
