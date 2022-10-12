#pragma once

#include "../Event.h"
#include "../../Background/Field.h"


class FieldEvent : public Event {
public:
    FieldEvent() = default;

    virtual ~FieldEvent() = default;

    virtual bool execute(void* obj) = 0;
};


