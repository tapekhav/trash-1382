#include "EventPlayerAddShield.h"

void EventPlayerAddShield::callReaction(std::shared_ptr<Player> player) {
    changeSpecification(player);
}

void EventPlayerAddShield::changeSpecification(std::shared_ptr<Player> player) {
    player->addShield(value);
}

EventPlayerAddShield::EventPlayerAddShield(int value): value(value){};