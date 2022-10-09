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
    return this->health;
};
int Player::getShield() const{
    return this->shield;
};
void Player::setHealth(int health){
    this->health = health;
    roundValue(this->health);
};

void Player::setShield(int shield) {
    this->shield = shield;
    roundValue(this->shield);
};

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

void Player::addXp(int xp){
    this->xp+=xp;
    roundValue(this->xp);
};

void Player::downHealth(int health){
    if (this->health <= health){
        this->health = 0;
    } else {
        this->health -= health;
    }
}

void Player::downShield(int shield){
    if (this->shield < shield){
        this->downHealth(shield - this->shield);
        this->shield = 0;
    } else {
        this->shield -= shield;
    }
}



void Player::roundValue(int& value){
    value = std::min(value, MAXVALUE);
}

int Player::getCoins() const {
    return coins;
}

void Player::addCoins(int coins) {
    this->coins += coins;
}
