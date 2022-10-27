#pragma once

#include <vector>
#include "../Logging/Subject.h"

class Player : public Subject {
public:
    explicit Player(LogOutInfo *info = nullptr, int health = 100, int armour = 100, int damage =
    10);

    ~Player() = default;

    int get_health() const;

    int get_armour() const;

    int get_coins() const;

    int get_damage() const;

    bool is_max_health() const;

    void set_health(int arg);

    void set_armour(int arg);

    void set_coins(int arg);

    void set_damage(int arg);

private:
    int health;
    int armour;
    int coins;
    int damage;
    int max_health;
    LogOutInfo* info;
};

