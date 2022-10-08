#ifndef LABS_ENEMY_H
#define LABS_ENEMY_H

#include "EventPlayer.h"

class Enemy: public EventPlayer {
public:
    void execute(Player& player) override;
    ~Enemy() override = default;
};


#endif //LABS_ENEMY_H
