#pragma once
#include "EventChangePassable.h"
class EventMakeNotPassable : public EventChangePassable{
    private:
        void check_field_passability();
    public:
        GameStatus trigger();
};