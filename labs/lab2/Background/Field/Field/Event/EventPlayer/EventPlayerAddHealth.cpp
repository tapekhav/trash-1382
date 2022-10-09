#include "EventPlayerAddHealth.h"


void EventPlayerAddHealth::callReaction(std::shared_ptr<Player> player) {
    changeSpecification(player);
}

void EventPlayerAddHealth::changeSpecification(std::shared_ptr<Player> player) {
    player->addHealth(value);
}

EventPlayerAddHealth::EventPlayerAddHealth(int value): value(value){};