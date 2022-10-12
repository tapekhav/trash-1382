#pragma once

#include "../Event.h"
#include "../../Background/Field.h"
#include "../../Characters/Player.h"

class RulesEvent : public Event {
public:
    RulesEvent() = default;

    virtual bool execute(void *obj) = 0;

    virtual ~RulesEvent() = default;
};



