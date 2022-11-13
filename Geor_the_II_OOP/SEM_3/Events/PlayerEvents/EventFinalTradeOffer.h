#pragma once
#include "EventPlayerVirtual.h"
class EventFinalTradeOffer : public EventPlayerVirtual{
    private:
        unsigned int price;
    public:
        EventFinalTradeOffer(Player *p, unsigned int pr);
        EventFinalTradeOffer(Player *p);
        EventFinalTradeOffer(const EventFinalTradeOffer& e);
        EventFinalTradeOffer(EventFinalTradeOffer&& e);
        EventFinalTradeOffer& operator=(const EventFinalTradeOffer& e);
        EventFinalTradeOffer& operator=(EventFinalTradeOffer&& e);
        GameStatus trigger();
        void set_price(unsigned int p);
        unsigned int get_price();
};