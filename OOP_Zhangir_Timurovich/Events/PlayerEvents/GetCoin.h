#pragma once

#include "PlayerEvent.h"

class GetCoin : public PlayerEvent {
public:
    GetCoin() = default;

    ~GetCoin() override = default;
    void execute(Player *player) override;
};

