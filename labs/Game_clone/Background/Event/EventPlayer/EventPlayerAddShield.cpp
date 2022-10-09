#include "EventPlayerAddShield.h"

EventPlayerAddShield::EventPlayerAddShield(int value): value(value){};

void EventPlayerAddShield::callReaction(std::shared_ptr<Player> player){
    EventPlayerAddShield::changeSpecification(player);
};
void EventPlayerAddShield::changeSpecification(std::shared_ptr<Player> player){
    player->addShield(value);
};
