#pragma once

#include "PlayerEvent.h"


class Heal : public PlayerEvent {
public:
    void execute(Player *player) override;
};
