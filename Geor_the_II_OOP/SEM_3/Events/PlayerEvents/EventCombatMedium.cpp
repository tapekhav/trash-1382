#include "EventCombatMedium.h"
GameStatus EventCombatMedium::trigger(){
    if(line_strangth > player->get_strength()){
        if(!player->add_hit_point(base_hit*strength_damage_modifier*(-1))){
            return lose;
        }
    }
    if(line_endurance > player->get_endurance()){
        if(!player->add_hit_point(base_hit*endurance_damage_modifier*(-1))){
            return lose;
        }
    }
    if(line_dexterity > player->get_dexterity()){
        if(!player->add_hit_point(base_hit*dexterity_damage_modifier*(-1))){
            return lose;
        }
    }
    if(line_armor > player->get_armor()){
        if(!player->add_hit_point(base_hit*armor_damage_modifier*(-1))){
            return lose;
        }
    }
    return null_event;
}