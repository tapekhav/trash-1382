#pragma once

#include "../Event.h"
#include "../../Background/Field.h"
#include "../../Characters/Player.h"

class RulesEvent : public Event {
    RulesEvent() = default;

    virtual void execute(void* obj) = 0;

    virtual ~RulesEvent() = default;
};



