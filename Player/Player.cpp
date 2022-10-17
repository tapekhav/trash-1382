#include "Player.h"

Player::Player(int Health, int AttackPower, bool Key):
    pHealth(Health), pAttackPower(AttackPower), pKey(Key) {};

Player::Player(const Player& obj): 
    Player(obj.pHealth, obj.pAttackPower, obj.pKey) {};

Player &Player::operator =(Player const &other){
    if(this == &other)
        return *this;
    this->pAttackPower = other.pAttackPower;
    this->pHealth = other.pHealth;
    this->pKey = other.pKey;
    return *this;
}




