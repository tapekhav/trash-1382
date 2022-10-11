#pragma once

#include "../Characters/Player.h"

class Event {
public:
    Event() = default;

    virtual void execute() = 0;

    Event(const Event &other) = default;

};

