#include "Enemy.h"

void Enemy::execute(Player &player) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution dmg(1, 5);
    std::uniform_int_distribution hp(1, 10);
    player.set_health(player.get_health() - dmg(rng));
    if (player.get_damage() > hp(rng))
        player.add_murder();
}
