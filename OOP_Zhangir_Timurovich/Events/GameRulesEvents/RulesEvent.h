#pragma once

#include "../Event.h"
#include "../../Background/Field.h"
#include "../../Characters/Player.h"

class RulesEvent : public Event {
public:

    virtual bool execute() = 0;

    virtual ~RulesEvent() = default;

protected:
    Player *player{};
};



