#include "EventBonus.h"
EventBonus::EventBonus(Player *p, int hp, int s, int e, int d, int a, long int c) : hit_point_bonus(hp), strength_bonus(s), endurance_bonus(e), dexterity_bonus(d), armor_bonus(a), coins_bonus(c){
    player = p;
}
EventBonus::EventBonus(Player *p) : hit_point_bonus(1), strength_bonus(1), endurance_bonus(1), dexterity_bonus(1), armor_bonus(1), coins_bonus(5){
    player = p;
}
EventBonus::EventBonus(const EventBonus& e){
    player = e.player;
    hit_point_bonus = e.hit_point_bonus;
    strength_bonus = e.strength_bonus;
    endurance_bonus = e.endurance_bonus;
    dexterity_bonus = e.dexterity_bonus;
    armor_bonus = e.armor_bonus;
    coins_bonus = e.coins_bonus;
}
EventBonus::EventBonus(EventBonus&& e){
    std::swap(player, e.player);
    std::swap(hit_point_bonus, e.hit_point_bonus);
    std::swap(strength_bonus, e.strength_bonus);
    std::swap(endurance_bonus, e.endurance_bonus);
    std::swap(dexterity_bonus, e.dexterity_bonus);
    std::swap(armor_bonus, e.armor_bonus);
    std::swap(coins_bonus, e.coins_bonus);
}
EventBonus& EventBonus::operator=(const EventBonus& e){
    if(this != &e){
        player = e.player;
        hit_point_bonus = e.hit_point_bonus;
        strength_bonus = e.strength_bonus;
        endurance_bonus = e.endurance_bonus;
        dexterity_bonus = e.dexterity_bonus;
        armor_bonus = e.armor_bonus;
        coins_bonus = e.coins_bonus;
    }
    return *this;
}
EventBonus& EventBonus::operator=(EventBonus&& e){
    if(this != &e){
        std::swap(player, e.player);
        std::swap(hit_point_bonus, e.hit_point_bonus);
        std::swap(strength_bonus, e.strength_bonus);
        std::swap(endurance_bonus, e.endurance_bonus);
        std::swap(dexterity_bonus, e.dexterity_bonus);
        std::swap(armor_bonus, e.armor_bonus);
        std::swap(coins_bonus, e.coins_bonus);
    }
    return *this;
}
GameStatus EventBonus::trigger(){
    player->add_hit_point(hit_point_bonus);
    player->add_strength(strength_bonus);
    player->add_endurance(endurance_bonus);
    player->add_dexterity(dexterity_bonus);
    player->add_armor(armor_bonus);
    if(!player->add_coins(coins_bonus)){
        player->set_coins(0);
    }
    return null_event;
}
void EventBonus::set_bonus(int hp, int s, int e, int d, int a, long int c){
    hit_point_bonus = hp;
    strength_bonus = s;
    endurance_bonus = e;
    dexterity_bonus = d;
    armor_bonus = a;
    coins_bonus = c;
}
void EventBonus::set_hit_point_bonus(int hp){
    hit_point_bonus = hp;
}
void EventBonus::set_strength_bonus(int s){
    strength_bonus = s;
}
void EventBonus::set_endurance_bonus(int e){
    endurance_bonus = e;
}
void EventBonus::set_dexterity_bonus(int d){
    dexterity_bonus = d;
}
void EventBonus::set_armor_bonus(int a){
    armor_bonus = a;
}
void EventBonus::set_coins_bonus(long int c){
    coins_bonus = c;
}
int EventBonus::get_hit_point_bonus(){
    return hit_point_bonus;
}
int EventBonus::get_strength_bonus(){
    return strength_bonus;
}
int EventBonus::get_endurance_bonus(){{
    return endurance_bonus;
}}
int EventBonus::get_dexterity_bonus(){
    return dexterity_bonus;
}
int EventBonus::get_armor_bonus(){
    return armor_bonus;
}
long int EventBonus::get_coins_bonus(){
    return coins_bonus;
}