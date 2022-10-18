#include "Trap.h"

Trap::Trap(Player *player) {
    this->player = player;
    std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<int> dmg(1, player->get_health());
    damage = dmg(rng);
}

void Trap::execute() {
    player->set_health(player->get_health() - damage);
    player->notify();
}