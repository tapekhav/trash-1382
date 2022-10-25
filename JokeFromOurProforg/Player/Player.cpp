#include "Player/Player.h"

Player::Player(const Player& obj) {
    mHunger = obj.mHunger;
    mThirst = obj.mThirst;
    mHealth = obj.mHealth;
}

Player& Player::operator =(Player const& other) {
    if (this == &other)
        return *this;
    mHealth = other.mHealth;
    mThirst = other.mThirst;
    mHunger = other.mHunger;
    return *this;
}

Player::Player(Player&& obj) {
    mHealth = obj.mHealth;
    obj.mHealth = 0;
    mThirst = obj.mThirst;
    obj.mThirst = 0;
    mHunger = obj.mHunger;
    obj.mHunger = 0;
}

void Player::DamagePlayer(int val) {
    mHealth = mHealth - val > EnumClass::HEALTH ? EnumClass::HEALTH : mHealth - val;
    Message* msg = new Message(EnumClass::LOG_HEALTH);
    msg->IncreaseData(&mHealth);
    Notify(*msg);
    delete msg;
}