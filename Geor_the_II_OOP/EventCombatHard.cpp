#include "EventCombatHard.h"
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