#pragma once
#include "EventCombat.h"
#include "GameStatus.h"
class EventCombatHard:EventCombat{
    public:
        GameStatus trigger();
};