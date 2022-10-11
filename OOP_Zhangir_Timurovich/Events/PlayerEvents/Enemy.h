#pragma once

#include "PlayerEvent.h"
#include <random>

class Enemy : public PlayerEvent {
public:
    Enemy() = default;

    ~Enemy() override = default;

    void execute(void *obj) override;
};

