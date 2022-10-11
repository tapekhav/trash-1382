#pragma once

#include "PlayerEvent.h"


class Heal : public PlayerEvent {
public:
    Heal() = default;

    ~Heal() override = default;

    void execute(Player *player) override;
};
