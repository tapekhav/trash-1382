#include "EventFinalTradeOffer.h"
EventFinalTradeOffer::EventFinalTradeOffer(Player *p, unsigned int pr) : price(pr){
    player = p;
}
EventFinalTradeOffer::EventFinalTradeOffer(Player *p) : price(10000){
    player = p;
}
EventFinalTradeOffer::EventFinalTradeOffer(const EventFinalTradeOffer& e) : price(e.price){
    player = e.player;
}
EventFinalTradeOffer::EventFinalTradeOffer(EventFinalTradeOffer&& e){
    std::swap(player, e.player);
    std::swap(price, e.price);
}
EventFinalTradeOffer& EventFinalTradeOffer::operator=(const EventFinalTradeOffer& e){
    if(this != &e){
        player = e.player;
        price = e.price;
    }
    return *this;
}
EventFinalTradeOffer& EventFinalTradeOffer::operator=(EventFinalTradeOffer&& e){
    if(this != &e){
        std::swap(player, e.player);
        std::swap(price, e.price);
    }
    return *this;
}
GameStatus EventFinalTradeOffer::trigger(){
    if(player->get_coins() >= price){
        return win;
    }
    return status_quo;
}
void EventFinalTradeOffer::set_price(unsigned int p){
    price = p;
}
unsigned int EventFinalTradeOffer::get_price(){
    return price;
}