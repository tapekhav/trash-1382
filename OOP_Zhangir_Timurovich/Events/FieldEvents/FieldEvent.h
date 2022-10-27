#pragma once

#include "../Event.h"
#include "../../Background/Field.h"
#include "../../Characters/Player.h"


class FieldEvent : public Event {
public:

    virtual ~FieldEvent() = default;

    virtual bool execute(LogOutInfo* info) = 0;

protected:
    Field* field{};
    Player* player{};
};


