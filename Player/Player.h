#ifndef PLAYER_H
#define PLAYER_H

#include "../Support/Enum.h"

class Player{
private:
    int pHealth;
    int pAttackPower;
    bool pKey;

public:
    Player(int Health = Enum::HEALTH, int AttackPower = Enum::ATTACK_POWER, bool Key = Enum::KEY_ABILITY);

    Player(const Player &obj);
    Player &operator=(Player const &other);

    int ShowSpeed();
};

#endif
