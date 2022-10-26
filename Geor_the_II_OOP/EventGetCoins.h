#pragma once
#include "EventPlayerVirtual.h"
#include "EventCombat.h"
#include <cmath>
class EventGetCoins : public EventPlayerVirtual{
    protected:
        long int coins;
        EventCombat *additional_event;
        void check_max_coins();
    public:
        EventGetCoins(Player *p, long int c, EventCombat *e);
        EventGetCoins(Player *p, long int c);
        EventGetCoins(Player *p);
        EventGetCoins(const EventGetCoins& e);
        EventGetCoins(EventGetCoins&& e);
        EventGetCoins& operator=(const EventGetCoins& e);
        EventGetCoins& operator=(EventGetCoins&& e);
        EventGetCoins& operator=(EventCombat& e);
        //EventGetCoins& operator=(EventCombat *e);
        //EventGetCoins& operator=(long int c);
        void set_coins(long int c);
        void set_additional_event(EventCombat *e);
        virtual GameStatus trigger();
        long int get_coins();
        EventCombat *get_additional_event();
};