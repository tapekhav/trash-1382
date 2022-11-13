#pragma once
#include "EventCombat.h"
class EventCombatHard:EventCombat{
    public:
        EventCombatHard(Player *p);
        EventCombatHard(Player *p, int bh);
        EventCombatHard(Player *p, int bh, int s, int e, int d, int a);
        EventCombatHard(Player *p, int bh, int s, int e, int d, int a, float sdm, float edm, float ddm, float adm);
        GameStatus trigger();
};