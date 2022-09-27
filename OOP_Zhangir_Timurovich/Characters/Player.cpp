#include "Player.h"

Player::Player(int health, int armour, int damage) {
    this->health = health;
    this->armour = armour;
    this->damage = damage;
    this->coins = 0;
}

int Player::get_health() const {
    return this->health;
}

int Player::get_armour() const {
    return this->armour;
}

int Player::get_coins() const {
    return this->coins;
}

int Player::get_damage() const {
    return this->damage;
}

void Player::add_health(int arg) {
    this->health += arg;
}

void Player::add_armour(int arg) {
    this->armour += arg;
}

void Player::add_coins(int arg) {
    this->coins += arg;
}
void Player::add_damage(int arg) {
    this->damage += arg;
}


