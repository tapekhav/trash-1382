#pragma once

#include "PlayerEvent.h"
#include <random>

class Enemy : public PlayerEvent {
public:
    void execute(Player *player) override;
};

