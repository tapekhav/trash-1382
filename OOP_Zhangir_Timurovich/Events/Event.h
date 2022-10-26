#pragma once

#include "../Characters/Player.h"
#include "../Logging/logs/GameObserver.h"
#include "../Logging/Subject.h"
#include "../Logging/Message.h"
# include "../Info/Structs.h"

class Event : public Subject {
public:

    virtual bool execute() = 0;

    virtual ~Event() = default;

};

