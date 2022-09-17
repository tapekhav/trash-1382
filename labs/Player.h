#ifndef LABS_PLAYER_H
#define LABS_PLAYER_H

#include "structs.h"

class Player {
public:
    explicit Player(int health = 1, int damage = 1, int xp = 1);
    Player(const Player& other) = delete;
    Player& operator=(const Player &other) = delete;
    Player(Player&& other) noexcept;
    Player& operator=(Player&& other) noexcept;
    void step(STEP s);
    int get_health() const;
    int get_damage() const;
    int get_xp() const;
    void set_health(int health);
    void set_damage(int damage);
    void add_xp(int xp);
private:
    int health, damage, xp;
};

#endif //LABS_PLAYER_H
