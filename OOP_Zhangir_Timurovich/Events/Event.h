#pragma once

#include "../Characters/Player.h"

class Event {
public:
    Event() = default;

    virtual void execute(void* obj) = 0;

    virtual ~Event() = default;

    Event(const Event &other) = default;

};

