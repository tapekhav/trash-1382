#include "EventCombatHard.h"
EventCombatHard::EventCombatHard(Player *p) : EventCombat(p){}
EventCombatHard::EventCombatHard(Player *p, int bh) : EventCombat(p, bh){}
EventCombatHard::EventCombatHard(Player *p, int bh, int s, int e, int d, int a) : EventCombat(p, bh, s, e, d, a){}
EventCombatHard::EventCombatHard(Player *p, int bh, int s, int e, int d, int a, float sdm, float edm, float ddm, float adm) : EventCombat(p, bh, s, e, d, a, sdm, edm, ddm, adm){}
GameStatus EventCombatHard::trigger(){
    int a = -1;
    if(line_strangth > player->get_strength()){
        a *= strength_damage_modifier;
    }
    if(line_endurance > player->get_endurance()){
        a *= endurance_damage_modifier;
    }
    if(line_dexterity > player->get_dexterity()){
        a *= dexterity_damage_modifier;
    }
    if(line_armor > player->get_armor()){
        a *= armor_damage_modifier;
    }
    if(!player->add_hit_point(a * base_hit)){
        return lose;
    }
    return null_event;
}