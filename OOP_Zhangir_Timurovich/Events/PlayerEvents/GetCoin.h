#pragma once

#include "PlayerEvent.h"

class GetCoin : public PlayerEvent {
public:
    explicit GetCoin(Player *player);

    ~GetCoin() override = default;

    bool execute(LogOutInfo* info) override;

};

