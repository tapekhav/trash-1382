#pragma once

#include "PlayerEvent.h"


class Heal : public PlayerEvent {
public:
    Heal(Player* player);

    ~Heal() override = default;

    bool execute(LogOutInfo* info) override;

};
