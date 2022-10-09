#include "EventPlayerAddCoin.h"

EventPlayerAddCoin::EventPlayerAddCoin(int value): value(value){};

void EventPlayerAddCoin::callReaction(std::shared_ptr<Player> player){
    EventPlayerAddCoin::changeSpecification(player);
};
void EventPlayerAddCoin::changeSpecification(std::shared_ptr<Player> player){
    player->addCoins(value);
};