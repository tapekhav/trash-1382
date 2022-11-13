#include "EventCombat.h"
void EventCombat::check_max_base_hit(){
    if(base_hit > MAX_BASE_HIT){
        base_hit = MAX_BASE_HIT;
    }
}
void EventCombat::check_max_strength_damage_modifier(){
    if(strength_damage_modifier > MAX_DAMAGE_MODIFIRE){
        strength_damage_modifier = MAX_DAMAGE_MODIFIRE;
    }
}
void EventCombat::check_max_endurance_damage_modifier(){
    if(endurance_damage_modifier > MAX_DAMAGE_MODIFIRE){
        endurance_damage_modifier = MAX_DAMAGE_MODIFIRE;
    }
}
void EventCombat::check_max_dexterity_damage_modifier(){
    if(dexterity_damage_modifier > MAX_DAMAGE_MODIFIRE){
        dexterity_damage_modifier = MAX_DAMAGE_MODIFIRE;
    }
}
void EventCombat::check_max_armor_damage_modifier(){
    if(armor_damage_modifier > MAX_DAMAGE_MODIFIRE){
        armor_damage_modifier = MAX_DAMAGE_MODIFIRE;
    }
}
void EventCombat::check_max_all(){
    check_max_base_hit();
    check_max_strength_damage_modifier();
    check_max_endurance_damage_modifier();
    check_max_dexterity_damage_modifier();
    check_max_armor_damage_modifier();
}
EventCombat::EventCombat(Player *p){
    player = p;
    base_hit = 20;
    line_strangth = 10;
    line_endurance = 10;
    line_dexterity = 10;
    line_armor = 10;
    strength_damage_modifier = 1.0;
    endurance_damage_modifier = 1.0;
    dexterity_damage_modifier = 1.0;
    armor_damage_modifier = 1.0;
}
EventCombat::EventCombat(Player *p, int bh){
    player = p;
    base_hit = abs(bh);
    check_max_base_hit();
    line_strangth = 10;
    line_endurance = 10;
    line_dexterity = 10;
    line_armor = 10;
    strength_damage_modifier = 1.0;
    endurance_damage_modifier = 1.0;
    dexterity_damage_modifier = 1.0;
    armor_damage_modifier = 1.0;
}
EventCombat::EventCombat(Player *p, int bh, int s, int e, int d, int a){
    player = p;
    base_hit = abs(bh);
    check_max_base_hit();
    line_strangth = s;
    line_endurance = e;
    line_dexterity = d;
    line_armor = a;
    strength_damage_modifier = 1.0;
    endurance_damage_modifier = 1.0;
    dexterity_damage_modifier = 1.0;
    armor_damage_modifier = 1.0;
}
EventCombat::EventCombat(Player *p, int bh, int s, int e, int d, int a, float sdm, float edm, float ddm, float adm){
    player = p;
    base_hit = abs(bh);
    line_strangth = s;
    line_endurance = e;
    line_dexterity = d;
    line_armor = a;
    strength_damage_modifier = abs(sdm);
    endurance_damage_modifier = abs(edm);
    dexterity_damage_modifier = abs(ddm);
    armor_damage_modifier = abs(adm);
    check_max_all();
}
EventCombat::EventCombat(const EventCombat& e) : base_hit(e.base_hit), line_strangth(e.line_strangth), line_endurance(e.line_endurance), line_dexterity(e.line_dexterity), line_armor(e.line_armor), strength_damage_modifier(e.strength_damage_modifier), endurance_damage_modifier(e.endurance_damage_modifier), dexterity_damage_modifier(e.dexterity_damage_modifier), armor_damage_modifier(e.armor_damage_modifier){
    player = e.player;
}
EventCombat::EventCombat(EventCombat&& e){
    std::swap(player, e.player);
    std::swap(base_hit, e.base_hit);
    std::swap(line_strangth, e.line_strangth);
    std::swap(line_endurance, e.line_endurance);
    std::swap(line_dexterity, e.line_dexterity);
    std::swap(line_armor, e.line_armor);
    std::swap(strength_damage_modifier, e.strength_damage_modifier);
    std::swap(endurance_damage_modifier, e.endurance_damage_modifier);
    std::swap(dexterity_damage_modifier, e.dexterity_damage_modifier);
    std::swap(armor_damage_modifier, e.armor_damage_modifier);
}
EventCombat& EventCombat::operator=(const EventCombat& e){
    if(this!=&e){
        player = e.player;
        base_hit = e.base_hit;
        line_strangth = e.line_strangth;
        line_endurance = e.endurance_damage_modifier;
        line_dexterity = e.line_dexterity;
        line_armor = e.line_armor;
        strength_damage_modifier = e.strength_damage_modifier;
        endurance_damage_modifier = e.endurance_damage_modifier;
        dexterity_damage_modifier = e.dexterity_damage_modifier;
        armor_damage_modifier = e.armor_damage_modifier;
    }
    return *this;
}
EventCombat& EventCombat::operator=(EventCombat&& e){
    if(this!=&e){
        std::swap(player, e.player);
        std::swap(base_hit, e.base_hit);
        std::swap(line_strangth, e.line_strangth);
        std::swap(line_endurance, e.line_endurance);
        std::swap(line_dexterity, e.line_dexterity);
        std::swap(line_armor, e.line_armor);
        std::swap(strength_damage_modifier, e.strength_damage_modifier);
        std::swap(endurance_damage_modifier, e.endurance_damage_modifier);
        std::swap(dexterity_damage_modifier, e.dexterity_damage_modifier);
        std::swap(armor_damage_modifier, e.armor_damage_modifier);
    }
    return *this;
}
void EventCombat::set_base_hit(int bh){
    base_hit = abs(bh);
    check_max_base_hit();
}
void EventCombat::set_line(int s, int e, int d, int a){
    line_strangth = s;
    line_endurance = e;
    line_dexterity = d;
    line_armor = a;
}
void EventCombat::set_damage_modifier(float sdm, float edm, float ddm, float adm){
    strength_damage_modifier = abs(sdm);
    endurance_damage_modifier = abs(edm);
    dexterity_damage_modifier = abs(ddm);
    armor_damage_modifier = abs(adm);
    check_max_all();
}
void EventCombat::set_line_strangth(int s){
    line_strangth = s;
}
void EventCombat::set_line_endurance(int e){
line_endurance = e;
}
void EventCombat::set_line_dexterity(int d){
line_dexterity = d;
}
void EventCombat::set_line_armor(int a){
line_armor = a;
}
void EventCombat::set_strength_damage_modifier(float sdm){
    strength_damage_modifier = abs(sdm);
    check_max_strength_damage_modifier();
}
void EventCombat::set_endurance_damage_modifier(float edm){
    endurance_damage_modifier = abs(edm);
    check_max_endurance_damage_modifier();
}
void EventCombat::set_dexterity_damage_modifier(float ddm){
    dexterity_damage_modifier = abs(ddm);
    check_max_dexterity_damage_modifier();
}
void EventCombat::set_armor_damage_modifier(float adm){
    armor_damage_modifier = abs(adm);
    check_max_armor_damage_modifier();
}
int EventCombat::get_line_strangth(){
    return line_strangth;
}
int EventCombat::get_line_endurance(){
    return line_endurance;
}
int EventCombat::get_line_dexterity(){
    return line_dexterity;
}
int EventCombat::get_line_armor(){
    return line_armor;
}
float EventCombat::get_strength_damage_modifier(){
    return strength_damage_modifier;
}
float EventCombat::get_endurance_damage_modifier(){
    return endurance_damage_modifier;
}
float EventCombat::get_dexterity_damage_modifier(){
    return dexterity_damage_modifier;
}
float EventCombat::get_armordamage_modifier(){
    return armor_damage_modifier;
}