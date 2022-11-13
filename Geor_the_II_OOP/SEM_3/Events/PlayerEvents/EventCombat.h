#pragma once
#include <cmath>
#include "EventPlayerVirtual.h"
#define MAX_BASE_HIT 3435973
#define MAX_DAMAGE_MODIFIRE 5.0
class EventCombat : public EventPlayerVirtual{
    protected:
        int base_hit;
        int line_strangth;
        int line_endurance;
        int line_dexterity;
        int line_armor;
        float strength_damage_modifier;
        float endurance_damage_modifier;
        float dexterity_damage_modifier;
        float armor_damage_modifier;
        void check_max_base_hit();
        void check_max_strength_damage_modifier();
        void check_max_endurance_damage_modifier();
        void check_max_dexterity_damage_modifier();
        void check_max_armor_damage_modifier();
        void check_max_all();
    public:
        EventCombat(Player *p);
        EventCombat(Player *p, int bh);
        EventCombat(Player *p, int bh, int s, int e, int d, int a);
        EventCombat(Player *p, int bh, int s, int e, int d, int a, float sdm, float edm, float ddm, float adm);
        EventCombat(const EventCombat& e);
        EventCombat(EventCombat&& e);
        EventCombat& operator=(const EventCombat& e);
        EventCombat& operator=(EventCombat&& e);
        virtual GameStatus trigger() = 0;
        void set_base_hit(int bh);
        void set_line(int s, int e, int d, int a);
        void set_damage_modifier(float sdm, float edm, float ddm, float adm);
        void set_line_strangth(int s);
        void set_line_endurance(int e);
        void set_line_dexterity(int d);
        void set_line_armor(int a);
        void set_strength_damage_modifier(float sdm);
        void set_endurance_damage_modifier(float edm);
        void set_dexterity_damage_modifier(float ddm);
        void set_armor_damage_modifier(float adm);
        int get_line_strangth();
        int get_line_endurance();
        int get_line_dexterity();
        int get_line_armor();
        float get_strength_damage_modifier();
        float get_endurance_damage_modifier();
        float get_dexterity_damage_modifier();
        float get_armordamage_modifier();
};