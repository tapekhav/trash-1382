#pragma once

#include "PlayerEvent.h"


class Heal : public PlayerEvent {
public:
    Heal() = default;

    ~Heal() override = default;

    bool execute(void *obj) override;
};
