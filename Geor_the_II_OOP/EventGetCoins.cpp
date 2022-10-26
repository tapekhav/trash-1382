#include "EventGetCoins.h"
void EventGetCoins::check_max_coins(){
    if(coins > (long int) UINT_MAX){
        coins = (long int) UINT_MAX;
    }
}
EventGetCoins::EventGetCoins(Player *p, long int c, EventCombat *e) : coins(c), additional_event(e){
    check_max_coins();
    player = p;
}
EventGetCoins::EventGetCoins(Player *p, long int c) : coins(c), additional_event(nullptr){
    check_max_coins();
    player = p;
}
EventGetCoins::EventGetCoins(Player *p) : coins(10), additional_event(nullptr){
    player = p;
}
EventGetCoins::EventGetCoins(const EventGetCoins& e) : coins(e.coins), additional_event(e.additional_event){
    player = e.player;
}
EventGetCoins::EventGetCoins(EventGetCoins&& e){
    std::swap(e.player, player);
    std::swap(e.coins, coins);
    std::swap(e.additional_event, additional_event);
}
EventGetCoins& EventGetCoins::operator=(const EventGetCoins& e){
    if(this != &e){
        player = e.player;
        coins = e.coins;
        additional_event = e.additional_event;
    }
    return *this;
}
EventGetCoins& EventGetCoins::operator=(EventGetCoins&& e){
    if(this != &e){
        std::swap(e.player, player);
        std::swap(e.coins, coins);
        std::swap(e.additional_event, additional_event);
    }
    return *this;
}
EventGetCoins& EventGetCoins::operator=(EventCombat& e){
    additional_event = &e;
    return *this;
}
/*EventGetCoins& EventGetCoins::operator=(EventCombat& *e){
    coins = 10;
    additional_event = e;
}*/
GameStatus EventGetCoins::trigger(){
    if(!player->add_coins(coins)){
        player->set_coins(0);
    }
    if(additional_event){
        return additional_event->trigger();
    }
    return null_event;
}
void EventGetCoins::set_coins(long int c){
    coins = c;
    check_max_coins();
}
void EventGetCoins::set_additional_event(EventCombat *e){
    additional_event = e;
}
long int EventGetCoins::get_coins(){
    return coins;
}
EventCombat *EventGetCoins::get_additional_event(){
    return additional_event;
}