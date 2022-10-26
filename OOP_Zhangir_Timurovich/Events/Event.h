#pragma once

#include "../Characters/Player.h"
#include "../Logging/logs/GameObserver.h"
#include "../Logging/Subject.h"

class Event : public Subject {
public:

    virtual bool execute() = 0;

    virtual ~Event() = default;

};

