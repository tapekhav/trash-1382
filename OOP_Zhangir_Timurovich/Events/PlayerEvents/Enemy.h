#pragma once

#include "PlayerEvent.h"
#include <random>

class Enemy : public PlayerEvent {
public:
    explicit Enemy(Player* player);

    ~Enemy() override = default;

    bool execute(LogOutInfo* info) override;

};

