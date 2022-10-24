#include "Player.h"

Player::Player(int lvl)
    : health(lvl * 5), xp(0), lvl(lvl), num_of_keys(0) {}

int Player::get_health() const {
    return health;
}

int Player::get_xp() const {
    return xp;
}

int Player::get_lvl() const {
    return lvl;
}

int Player::get_keys() const {
    return num_of_keys;
}

void Player::set_health(int health) {
     this->health = health;
}

void Player::set_xp(int xp) {
    this->xp = xp;
}

void Player::add_lvl() {
    ++lvl;
}

void Player::add_key() {
    ++num_of_keys;
}
