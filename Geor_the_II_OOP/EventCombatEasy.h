#pragma once
#include "GameStatus.h"
#include "EventCombat.h"
class EventCombatEasy : public EventCombat{
    public:
        virtual GameStatus trigger();
};