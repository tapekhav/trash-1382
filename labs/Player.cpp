#include "Player.h"

Player::Player(unsigned int health,
               unsigned int shield,
               unsigned int damage,
               unsigned int xp,
               Gender gender):
                health(health),
                shield(shield),
                damage(damage),
                xp(xp),
                gender(gender){}

unsigned int Player::getHealth() const{
    return this->health;
};
unsigned int Player::getShield() const{
    return this->shield;
};

unsigned int Player::getDamage() const{
    return this->damage;
};
Player::Gender Player::getGender() const{
    return this->gender;
};

void Player::setHealth(unsigned int health){
    this->health = health;
};

void Player::setShield(unsigned int shield) {
    this->shield = shield;
};

void Player::setDamage(unsigned int damage){
    this->damage = damage;
};

void Player::addHealth(unsigned int health){
    this->health+=health;
};

void Player::addShield(unsigned int shield){
    this->shield+=shield;
};

void Player::addXp(unsigned int xp){
    this->xp+=xp;
};
