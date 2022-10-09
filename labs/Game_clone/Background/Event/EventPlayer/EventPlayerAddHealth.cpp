#include "iostream"
#include "EventPlayerAddHealth.h"



EventPlayerAddHealth::EventPlayerAddHealth(int value): value(value){};

void EventPlayerAddHealth::callReaction(std::shared_ptr<Player> player){
    EventPlayerAddHealth::changeSpecification(player);
};
void EventPlayerAddHealth::changeSpecification(std::shared_ptr<Player> player){
    player->addHealth(value);
};
