#include "Heal.h"

void Heal::execute(Player &player) {
    int max_health = player.get_lvl() * 5;
    if (player.get_health() < max_health)
        player.set_health(player.get_health() + 1);
    else
        player.set_health(max_health);

    player.Notify();
}
