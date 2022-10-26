#ifndef SURVIVAL_PLAYER_H
#define SURVIVAL_PLAYER_H

#include "Enums.h"
#include "Logging/Subject.h"

class Player : public Subject{
public:
    Player() :mHealth(EnumClass::HEALTH), mThirst(EnumClass::THIRST), mHunger(EnumClass::HUNGER) {};
    Player(const Player& obj);
    Player(Player&& obj);

    Player& operator =(Player const& other);

    int GetHealth() const { return mHealth; }
    int GetHunger() const { return mHunger; }
    int GetThirst() const { return mThirst; }

    void DamagePlayer(int val);
    void HealPlayer(int val); 
    void SetThirst(int val);
    void LoseThirstUnit();

    void SetHunger(int val);
    void LoseHungerUnit();

private:
    void CreateMessage(EnumClass::Log type, int* data);

    int mThirst;
    int mHunger;
    int mHealth;
};

#endif //SURVIVAL_PLAYER_H