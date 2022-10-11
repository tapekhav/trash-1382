#include <iostream>
#include "EventPlayerAddCoin.h"

EventPlayerAddCoin::EventPlayerAddCoin(int value): value(value){};

void EventPlayerAddCoin::changeSpecification(Player *player){
    player->addCoins(value);
};