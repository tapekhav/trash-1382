#include "Player.h"

Player::Player(int health, int armour, int damage) {
    this->health = health;
    this->max_health = health;
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

void Player::set_health(int arg) {
    this->health = arg;
}

void Player::set_armour(int arg) {
    this->armour = arg;
}

void Player::set_coins(int arg) {
    this->coins = arg;
}

void Player::set_damage(int arg) {
    this->damage = arg;
}

bool Player::is_max_health() const {
    return this->health == this->max_health;
}



