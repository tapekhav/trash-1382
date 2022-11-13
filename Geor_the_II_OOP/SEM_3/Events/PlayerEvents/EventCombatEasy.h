#pragma once
#include "EventCombat.h"
class EventCombatEasy : public EventCombat{
    public:
        virtual GameStatus trigger();
};