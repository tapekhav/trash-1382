#pragma once
#include "EventPlayerVirtual.h"
class EventBonus : public EventPlayerVirtual{
    private:
        int hit_point_bonus;
        int strength_bonus;
        int endurance_bonus;
        int dexterity_bonus;
        int armor_bonus;
        long int coins_bonus;
    public:
        EventBonus(Player *p, int hp, int s, int e, int d, int a, long int c);
        EventBonus(Player *p);
        EventBonus(const EventBonus& e);
        EventBonus(EventBonus&& e);
        EventBonus& operator=(const EventBonus& e);
        EventBonus& operator=(EventBonus&& e);
        GameStatus trigger();
        void set_bonus(int hp, int s, int e, int d, int a, long int c);
        void set_hit_point_bonus(int hp);
        void set_strength_bonus(int s);
        void set_endurance_bonus(int e);
        void set_dexterity_bonus(int d);
        void set_armor_bonus(int a);
        void set_coins_bonus(long int c);
        int get_hit_point_bonus();
        int get_strength_bonus();
        int get_endurance_bonus();
        int get_dexterity_bonus();
        int get_armor_bonus();
        long int get_coins_bonus();
};