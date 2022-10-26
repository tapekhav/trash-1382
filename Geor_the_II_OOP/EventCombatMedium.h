#pragma once
#include "GameStatus.h"
#include "EventCombat.h"
class EventCombatMedium : public EventCombat{
    public:
        GameStatus trigger();
};