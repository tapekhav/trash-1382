#pragma once
#include "EventFieldVirtual.h"
class EventMakeAllPassable : public EventFieldVirtual{
    public:
        GameStatus trigger();
};