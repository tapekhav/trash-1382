#include "Player.h"

Player::Player(int health, int damage, int xp)
    : health(health), damage(damage), xp(xp) {}

int Player::get_damage() const {
    return damage;
}

int Player::get_health() const {
    return health;
}

int Player::get_xp() const {
    return xp;
}

void Player::set_health(int health) {
     this->health = health;
}

void Player::set_damage(int damage) {
    this->damage = damage;
}

void Player::set_xp(int xp) {
    this->xp += xp;
}

