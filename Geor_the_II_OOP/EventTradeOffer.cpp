#include "EventTradeOffer.h"
EventTradeOffer::EventTradeOffer(Player *p, unsigned int pr, int hp, int s, int e, int d, int a) : price(pr), hit_point_bonus(hp), strength_bonus(s), endurance_bonus(e), dexterity_bonus(d), armor_bonus(a){
    player = p;
}
EventTradeOffer::EventTradeOffer(Player *p, unsigned int pr) : price(pr), hit_point_bonus(5), strength_bonus(5), endurance_bonus(5), dexterity_bonus(5), armor_bonus(5){
    player = p;
}
EventTradeOffer::EventTradeOffer(Player *p) : price(100), hit_point_bonus(5), strength_bonus(5), endurance_bonus(5), dexterity_bonus(5), armor_bonus(5){
    player = p;
}
EventTradeOffer::EventTradeOffer(const EventTradeOffer& e) : price(e.price), hit_point_bonus(e.hit_point_bonus), strength_bonus(e.strength_bonus), endurance_bonus(e.endurance_bonus), dexterity_bonus(e.dexterity_bonus), armor_bonus(e.armor_bonus){
    player = e.player;
}
EventTradeOffer::EventTradeOffer(EventTradeOffer&& e){
    std::swap(player, e.player);
    std::swap(price, e.price);
    std::swap(hit_point_bonus, e.hit_point_bonus);
    std::swap(strength_bonus, e.strength_bonus);
    std::swap(endurance_bonus, e.endurance_bonus);
    std::swap(dexterity_bonus, e.dexterity_bonus);
    std::swap(armor_bonus, e.armor_bonus);
}
EventTradeOffer& EventTradeOffer::operator=(const EventTradeOffer& e){
    if(this != &e){
        player = e.player;
        price = e.price;
        hit_point_bonus = e.hit_point_bonus;
        strength_bonus = e.strength_bonus;
        endurance_bonus = e.endurance_bonus;
        dexterity_bonus = e.dexterity_bonus;
        armor_bonus = e.armor_bonus;
    }
    return *this;
}
EventTradeOffer& EventTradeOffer::operator=(EventTradeOffer&& e){
    if(this != &e){
        std::swap(player, e.player);
        std::swap(price, e.price);
        std::swap(hit_point_bonus, e.hit_point_bonus);
        std::swap(strength_bonus, e.strength_bonus);
        std::swap(endurance_bonus, e.endurance_bonus);
        std::swap(dexterity_bonus, e.dexterity_bonus);
        std::swap(armor_bonus, e.armor_bonus);
    }
    return *this;
}
GameStatus EventTradeOffer::trigger(){
    if(player->add_coins(((long int) price) * (-1))){
        player->add_hit_point(hit_point_bonus);
        player->add_strength(strength_bonus);
        player->add_endurance(endurance_bonus);
        player->add_dexterity(dexterity_bonus);
        player->add_armor(armor_bonus);
    }
    return null_event;
}
void EventTradeOffer::set_price(unsigned int p){
    price = p;
}
void EventTradeOffer::set_bonus(int hp, int s, int e, int d, int a){
    hit_point_bonus = hp;
    strength_bonus = s;
    endurance_bonus = e;
    dexterity_bonus = d;
    armor_bonus = a;
}
void EventTradeOffer::set_hit_point_bonus(int hp){
    hit_point_bonus = hp;
}
void EventTradeOffer::set_strength_bonus(int s){
    strength_bonus = s;
}
void EventTradeOffer::set_endurance_bonus(int e){
    endurance_bonus = e;
}
void EventTradeOffer::set_dexterity_bonus(int d){
    dexterity_bonus = d;
}
void EventTradeOffer::set_armor_bonus(int a){
    armor_bonus = a;
}
unsigned int EventTradeOffer::get_price(){
    return price;
}
int EventTradeOffer::get_hit_point_bonus(){
    return hit_point_bonus;
}
int EventTradeOffer::get_strength_bonus(){
    return strength_bonus;
}
int EventTradeOffer::get_endurance_bonus(){
    return endurance_bonus;
}
int EventTradeOffer::get_dexterity_bonus(){
    return dexterity_bonus;
}
int EventTradeOffer::get_armor_bonus(){
    return armor_bonus;
}