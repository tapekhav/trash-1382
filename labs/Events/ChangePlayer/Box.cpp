#include "Box.h"

void Box::execute(Player &player) {
    player.set_xp(player.get_xp() + 10);
    if (player.get_xp() == player.get_lvl() * 10) {
        player.add_lvl();
        player.set_damage(player.get_damage() + 5);
        player.set_xp(0);
    }
}
