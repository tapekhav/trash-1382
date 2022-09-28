#pragma once

#include <vector>

class Player {
public:
    explicit Player(int health = 100, int armour = 100, int damage = 10);

    ~Player() = default;
    int get_health() const;
    int get_armour() const;
    int get_coins() const;
    int get_damage() const;
    void add_health(int arg);
    void add_armour(int arg);
    void add_coins(int arg);
    void add_damage(int arg);

private:
    int health;
    int armour;
    int coins;
    int damage;
};

