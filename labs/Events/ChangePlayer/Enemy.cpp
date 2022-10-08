//
// Created by vladimir on 25.09.22.
//

#include "Enemy.h"

void Enemy::execute(Player &player) {
    player.set_health(player.get_health() - 1);
}
