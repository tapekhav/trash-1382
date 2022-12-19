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
    Message* msg = new StatusDecorator(new IntMessage(mHealth, "Decrease health"));
    Notify(msg);
    delete msg;
}

void Player::HealPlayer(int val) {
    mHealth = mHealth + val > EnumClass::HEALTH ? EnumClass::HEALTH : mHealth + val;
    Message* msg = new StatusDecorator(new IntMessage(mHealth, "Increase health"));
    Notify(msg);
    delete msg;
}

void Player::LoseHungerUnit() {
    mHunger = mHunger - 1 < 0 ? 0 : mHunger - 1;
    Message* msg = new StatusDecorator(new IntMessage(mHunger, "Lose hunger unit"));
    Notify(msg);
    delete msg;
}

void Player::LoseThirstUnit() {
    mThirst = mThirst - 1 < 0 ? 0 : mThirst - 1;
    Message* msg = new StatusDecorator(new IntMessage(mThirst, "Lose thirsty unit"));
    Notify(msg);
    delete msg;
}

void Player::SetHunger(int val) {
    mHunger = mHunger + val > EnumClass::HUNGER ? EnumClass::HUNGER : mHunger + val;
    Message* msg = new StatusDecorator(new IntMessage(mHunger, "Increase hunger"));
    Notify(msg);
    delete msg;
}

void Player::SetThirst(int val) {
    mThirst = mThirst + val > EnumClass::THIRST ? EnumClass::THIRST : mThirst + val; 
    Message* msg = new StatusDecorator(new IntMessage(mThirst, "Increase thirsty"));
    Notify(msg);
    delete msg;
}