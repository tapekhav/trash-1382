#include "PlayerView.h"

PlayerView::PlayerView(Player *other) : player(other) {
    player->Attach(this);
}

void PlayerView::update() {
    print();
}

void PlayerView::print() const {
    std::cout << "hp = " << player->get_health() << " lvl = " << player->get_lvl()
              << " xp = " << player->get_xp() << '\n';
}
