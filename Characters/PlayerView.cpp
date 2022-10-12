#include "PlayerView.h"

PlayerView::PlayerView(Player *other) : player(other) {
    player->Attach(this);
}

void PlayerView::update() {
    std::cout << "hp = " << player->get_health() << " lvl = " << player->get_lvl()
              << " xp = " << player->get_xp() << " key = " << player->get_keys() << '\n';
}
