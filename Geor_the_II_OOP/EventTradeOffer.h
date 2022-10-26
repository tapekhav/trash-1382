#pragma once
#include "EventPlayerVirtual.h"
class EventTradeOffer : EventPlayerVirtual{
    private:
        unsigned int price;
        int hit_point_bonus;
        int strength_bonus;
        int endurance_bonus;
        int dexterity_bonus;
        int armor_bonus;
    public:
        EventTradeOffer(Player *p, unsigned int pr, int hp, int s, int e, int d, int a);
        EventTradeOffer(Player *p, unsigned int pr);
        EventTradeOffer(Player *p);
        EventTradeOffer(const EventTradeOffer& e);
        EventTradeOffer(EventTradeOffer&& e);
        EventTradeOffer& operator=(const EventTradeOffer& e);
        EventTradeOffer& operator=(EventTradeOffer&& e);
        GameStatus trigger();
        void set_price(unsigned int p);
        void set_bonus(int hp, int s, int e, int d, int a);
        void set_hit_point_bonus(int hp);
        void set_strength_bonus(int s);
        void set_endurance_bonus(int e);
        void set_dexterity_bonus(int d);
        void set_armor_bonus(int a);
        unsigned int get_price();
        int get_hit_point_bonus();
        int get_strength_bonus();
        int get_endurance_bonus();
        int get_dexterity_bonus();
        int get_armor_bonus();
};