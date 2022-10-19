#include <iostream>
#include "Player.h"

#define MAXVALUE 100

Player::Player(int health,
               int shield,
               int xp,
               int coins):
        health(health),
        shield(shield),
        xp(xp),
        coins(coins){}

int Player::getHealth() const{
    return health;
};
int Player::getShield() const{
    return shield;
};
int Player::getXp() const{
    return xp;
}
int Player::getCoins() const {
    return coins;
}


void Player::addHealth(int health){
    this->health+=health;
    roundValue(this->health);
    std::cout << "Health " << this->health << '\n';
};
void Player::addShield(int shield){
    this->shield+=shield;
    roundValue(this->shield);
    std::cout << "Shield " << this->shield << '\n';
};
void Player::addCoins(int coins) {
    this->coins += coins;
    std::cout << "Coins " << this->coins << '\n';
}


void Player::downHealth(int health){
    if (this->health <= health){
        this->health = 0;
    } else {
        this->health -= health;
    }
    std::cout << "Health " << this->health << '\n';
}
void Player::takeDamage(int shield){
    if (this->shield < shield){
        this->downHealth(shield - this->shield);
        this->shield = 0;
    } else {
        this->shield -= shield;
    }
    std::cout << "Shield " << this->shield << '\n';
}
void Player::downCoins(int coins){
    if (this->coins < coins){
        this->coins = 0;
    } else {
        this->coins -= coins;
    }
    std::cout << "Coins " << this->coins << '\n';
}




void Player::roundValue(int& value){
    value = std::min(value, MAXVALUE);
}


