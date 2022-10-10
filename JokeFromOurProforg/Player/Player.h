#ifndef SURVIVAL_PLAYER_H
#define SURVIVAL_PLAYER_H

#include "Enums.h"

class Player {
public:
    Player() :mHealth(EnumClass::HEALTH), mThirst(EnumClass::THIRST), mHunger(EnumClass::HUNGER) {};
    Player(const Player& obj);
    Player(Player&& obj);

    Player& operator =(Player const& other);

    int GetHealth() const { return mHealth; }
    int GetHunger() const { return mHunger; }
    int GetThirst() const { return mThirst; }

    void DamagePlayer(int val) { mHealth = mHealth - val > EnumClass::HEALTH ? EnumClass::HEALTH : mHealth - val; }
    void HealPlayer(int val) { mHealth = mHealth + val > EnumClass::HEALTH ? EnumClass::HEALTH : mHealth + val;  }

    void SetThirst(int val) { mThirst = mThirst + val > EnumClass::THIRST ? EnumClass::THIRST : mThirst + val; }
    void LoseThirstUnit() { mThirst = mThirst - 1 < 0 ? 0 : mThirst - 1; }

    void SetHunger(int val) { mHunger = mHunger + val > EnumClass::HUNGER ? EnumClass::HUNGER : mHunger + val; }
    void LoseHungerUnit() { mHunger = mHunger - 1 < 0 ? 0 : mHunger - 1; }
private:
    int mThirst;
    int mHunger;
    int mHealth;
};

#endif //SURVIVAL_PLAYER_H