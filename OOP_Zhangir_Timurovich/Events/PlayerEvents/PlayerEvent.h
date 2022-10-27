#pragma once

#include "../Event.h"
#include "../../Characters/Player.h"

class PlayerEvent : public Event {
public:

    virtual bool execute(LogOutInfo *info) = 0;

    virtual ~PlayerEvent() = default;

protected:
    Player *player{};
};

