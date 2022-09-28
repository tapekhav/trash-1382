//
// Created by vladimir on 25.09.22.
//

#include "Heal.h"

void Heal::execute(Player &player) {
    player.set_health(player.get_health() + 5);
}
