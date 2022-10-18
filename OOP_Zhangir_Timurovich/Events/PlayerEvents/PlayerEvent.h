#pragma once

#include "../Event.h"
#include "../../Characters/Player.h"

class PlayerEvent : public Event {
public:
//    PlayerEvent(Player *player);

    virtual bool execute() = 0;

    virtual ~PlayerEvent() = default;

private:
    Player *player{};
};

