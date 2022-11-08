#pragma once

#include "../Characters/Player.h"
#include "../Logging/logs/GameObserver.h"
#include "../Logging/Subject.h"
#include "../Logging/Message.h"
#include "../Info/Enums.h"
#include "../Info/LogOutInfo.h"

class Event : public Subject {
public:

    virtual bool execute(LogOutInfo* info) = 0;

    virtual ~Event() = default;

};

