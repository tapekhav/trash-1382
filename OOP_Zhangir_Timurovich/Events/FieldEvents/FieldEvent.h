#pragma once

#include "../Event.h"
#include "../../Background/Field.h"


class FieldEvent : public Event {
public:
    FieldEvent() = default;

    virtual ~FieldEvent() = default;

    virtual void execute(Field &field) = 0;

    void execute(Player *pPlayer) override {};
};


