#pragma once

#include "../Characters/Player.h"

class Event {
public:

    virtual bool execute() = 0;

    virtual ~Event() = default;

};

