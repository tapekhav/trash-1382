#include "EventCombatEasy.h"
GameStatus EventCombatEasy::trigger(){
    if(line_strangth > player->get_strength() && line_endurance > player->get_endurance() && line_dexterity > player->get_dexterity() && line_armor > player->get_armor()){
        player->add_hit_point(base_hit*strength_damage_modifier*endurance_damage_modifier*dexterity_damage_modifier*armor_damage_modifier*(-1));
    }
    return null_event;
}