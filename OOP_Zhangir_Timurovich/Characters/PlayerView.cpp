#include "PlayerView.h"

PlayerView::PlayerView(Player *player) {
    this->player_obj = player;
}

void PlayerView::show_chars() {
    std::cout << "Health: " << player_obj->get_health() << " ";
    std::cout << "Armour: " << player_obj->get_armour() << "\n";
    std::cout << "Coins: " << player_obj->get_coins() << " ";
    std::cout << "Damage: " << player_obj->get_damage() << "\n";
}