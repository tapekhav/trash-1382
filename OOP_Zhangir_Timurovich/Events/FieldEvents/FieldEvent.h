#pragma once

#include "../Event.h"
#include "../../Background/Field.h"


class FieldEvent : public Event {
public:
    virtual void execute(Field& field) = 0;
    void execute(Player *pPlayer) override {};
};


