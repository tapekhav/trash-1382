#pragma once

#include "PlayerEvent.h"

class GetCoin : public PlayerEvent {
public:
    GetCoin(Player *player);

    ~GetCoin() override = default;

    bool execute() override;

};

