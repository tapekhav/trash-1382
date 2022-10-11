#pragma once

#include "PlayerEvent.h"

class GetCoin : public PlayerEvent {
public:
    void execute(Player *player) override;
};

