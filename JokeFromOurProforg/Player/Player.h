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

    void DamagePlayer(int val);
    void SetThirst();
    void SetHunger();
private:
    int mThirst;
    int mHunger;
    int mHealth;
};

#endif //SURVIVAL_PLAYER_H