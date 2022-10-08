#include "Heal.h"

void Heal::execute(Player &player) {
    if (player.get_health() - 5 < player.get_lvl() * 5)
        player.set_health(player.get_health() + 5);
    else
        player.set_health(player.get_lvl() * 5);
}
