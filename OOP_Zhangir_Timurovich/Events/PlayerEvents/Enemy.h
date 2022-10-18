#pragma once

#include "PlayerEvent.h"
#include <random>

class Enemy : public PlayerEvent {
public:
    Enemy(Player* player);

    ~Enemy() override = default;

    bool execute() override;

private:
    Player *player;
};

