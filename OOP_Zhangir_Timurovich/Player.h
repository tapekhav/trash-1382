#pragma once

#include <vector>

class Player {
public:
    explicit Player(int health = 100, int armour = 100, int damage = 10);

    ~Player() = default;

private:
    int health;
    int armour;
    int coins;
    int damage;
};

