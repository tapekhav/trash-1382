#include "Enemy.h"

bool Enemy::execute() {
    if (player) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution <std::mt19937::result_type> dmg(1, 5);
        std::uniform_int_distribution <std::mt19937::result_type> hp(1, 10);
        player->set_health(player->get_health() - (int) dmg(rng));
        if (player->get_damage() > hp(rng)) {
            player->set_coins(player->get_coins() + 5);
        } else {
            player->set_coins(player->get_coins() - 5);
            player->set_health(player->get_health() - (int) dmg(rng));
        }
        Message message(GAME, "Event happened");
        notify(message);
        return true;
    }
    return false;
}

Enemy::Enemy(Player *player) {
    this->player = player;
}



