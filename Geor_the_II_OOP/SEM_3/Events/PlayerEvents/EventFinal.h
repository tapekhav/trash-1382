#pragma once
#include "EventCombatHard.h"
class EventFinal : public EventPlayerVirtual{
    private:
        int line_strangth;
        int line_endurance;
        int line_dexterity;
        int line_armor;
        EventCombatHard *boss;
    public:
        EventFinal(Player *p, int s, int e, int d, int a, EventCombatHard *b);
        EventFinal(Player *p, int s, int e, int d, int a);
        EventFinal(Player *p);
        EventFinal(const EventFinal& e);
        EventFinal(EventFinal&& e);
        EventFinal& operator=(const EventFinal& e);
        EventFinal& operator=(EventFinal&& e);
        GameStatus trigger();
        void set_line(int s, int e, int d, int a);
        void set_line_strangth(int s);
        void set_line_endurance(int e);
        void set_line_dexterity(int d);
        void set_line_armor(int a);
        void set_boss(EventCombatHard *b);
        int get_line_strangth();
        int get_line_endurance();
        int get_line_dexterity();
        int get_line_armor();
        EventCombatHard *get_boss();
};