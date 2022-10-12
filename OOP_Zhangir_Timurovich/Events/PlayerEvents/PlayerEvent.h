#pragma once

#include "../Event.h"
#include "../../Characters/Player.h"

class PlayerEvent : public Event {
public:
    PlayerEvent() = default;

    virtual void execute(void* obj) = 0;

    virtual ~PlayerEvent() = default;

};

