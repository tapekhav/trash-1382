#include "PlayerView.h"

PlayerView::PlayerView(Player *other) : player(other) {}

void PlayerView::update() {
    std::cout << "hp = " << player->get_health() << " lvl = " << player->get_lvl()
              << " xp = " << player->get_xp() << " num_of_keys = " << player->get_keys() << '\n';
}
