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
    CreateMessage(EnumClass::LOG_HEALTH, &mHealth);
}

void Player::HealPlayer(int val) { 
    mHealth = mHealth + val > EnumClass::HEALTH ? EnumClass::HEALTH : mHealth + val;
    CreateMessage(EnumClass::LOG_HEALTH, &mHealth);
}

void Player::SetHunger(int val) {
    mHunger = mHunger + val > EnumClass::HUNGER ? EnumClass::HUNGER : mHunger + val;
    CreateMessage(EnumClass::LOG_HUNGER, &mHunger);
}

void Player::LoseHungerUnit() {
    mHunger = mHunger - 1 < 0 ? 0 : mHunger - 1;
    CreateMessage(EnumClass::LOG_HUNGER, &mHunger);
}

void Player::SetThirst(int val) {
    mThirst = mThirst + val > EnumClass::THIRST ? EnumClass::THIRST : mThirst + val;
    CreateMessage(EnumClass::LOG_THIRST, &mThirst);
}

void Player::LoseThirstUnit() { 
    mThirst = mThirst - 1 < 0 ? 0 : mThirst - 1;
    CreateMessage(EnumClass::LOG_THIRST, &mThirst);
}

void Player::CreateMessage(EnumClass::Log type, int* data) {
    Message* msg = new Message(type);
    msg->IncreaseData(data);
    Notify(msg);
    delete msg;
}

