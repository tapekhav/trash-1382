#pragma once

#include "../Event.h"
#include "../../Characters/Player.h"

class PlayerEvent : public Event {
public:
    PlayerEvent() = default;

    virtual void execute(Player *player) = 0;

    virtual ~PlayerEvent() = default;

    void execute() override {};
};

