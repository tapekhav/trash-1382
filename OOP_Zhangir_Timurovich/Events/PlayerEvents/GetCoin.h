#pragma once

#include "PlayerEvent.h"

class GetCoin : public PlayerEvent {
public:
    GetCoin() = default;

    ~GetCoin() override = default;
    bool execute(void *obj) override;
};

