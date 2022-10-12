#include "Trap.h"

void Trap::execute(Player &player) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution dmg(1, player.get_health());
    player.set_health(player.get_health() - dmg(rng));
    player.Notify();
}
