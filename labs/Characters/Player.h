#ifndef LABS_PLAYER_H
#define LABS_PLAYER_H

#include <algorithm>

class Player {
public:
    enum STEP {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        STOP,
        EXIT
    };
    explicit Player(int health = 5, int damage = 5, int xp = 0);

    int get_health() const;
    int get_lvl() const;
    int get_damage() const;
    int get_xp() const;

    void set_health(int health);
    void set_damage(int damage);
    void set_xp(int xp);
    void add_lvl();
private:
    int health;
    int damage;
    int xp;
    int lvl;
};

#endif //LABS_PLAYER_H
