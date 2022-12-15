#include "Player.h"

Player::Player(int lvl)
    : health(lvl * 5), xp(0), lvl(lvl), num_of_keys(0) {}

Player::Player(const Player &other) : health(other.health), xp(other.xp),
                                      num_of_keys(other.num_of_keys), lvl(other.lvl) {}

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
    notify(Message(Message::Game, "player's health was changed", this->health));
}

void Player::set_xp(int xp) {
    this->xp = xp;
    notify(Message(Message::Game, "player's xp was changed", this->xp));
}

void Player::add_lvl() {
    ++lvl;
    notify(Message(Message::Game, "player's lvl was changed", lvl));
}

void Player::add_key() {
    ++num_of_keys;
    notify(Message(Message::Game, "player's count of keys was changed", num_of_keys));
}

void Player::restore(Memento *) {
    //TODO restore
}

Memento *Player::save() {
    std::string s("Player: " + std::to_string(hash_func(health, xp, lvl, num_of_keys)) + '\n');
    s += std::to_string(health) + " " + std::to_string(xp) + " "
            + std::to_string(lvl) + " " + std::to_string(num_of_keys) + '\n';

    return new Memento(s);
}

size_t Player::hash_func(int health, int xp, int lvl, int num_of_keys) {
    size_t hash_health = std::hash<int>()(health);
    size_t hash_xp = std::hash<int>()(xp);
    size_t hash_lvl = std::hash<int>()(lvl);
    size_t hash_num_of_keys = std::hash<int>()(num_of_keys);

    return (hash_health << 10) + (hash_xp << 5) + (hash_lvl >> 1) + (hash_num_of_keys << 2);
}
