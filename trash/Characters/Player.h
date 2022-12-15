#ifndef LABS_PLAYER_H
#define LABS_PLAYER_H

#include <algorithm>
#include "../Logging/LogLevel/Subject.h"
#include "../../Save/Memento/Originator.h"

class Player : public Subject, public Originator {
public:
    enum STEP {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        SAVE,
        LOAD,
        STOP,
        EXIT
    };
    explicit Player(int lvl = 1);
    Player(const Player&);

    int get_health() const;
    int get_lvl()    const;
    int get_xp()     const;
    int get_keys()   const;

    void set_health(int);
    void set_xp(int);
    void add_lvl();
    void add_key();

    void restore(Memento*) final;
    Memento* save() final;
private:
    size_t hash_func(int, int, int, int);

    int health;
    int xp;
    int lvl;
    int num_of_keys;
};

#endif //LABS_PLAYER_H
