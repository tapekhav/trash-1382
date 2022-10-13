#include "EventPlayerAddShield.h"


void EventPlayerAddShield::changeSpecification(Player* player) {
    player->addShield(value);
}

EventPlayerAddShield::EventPlayerAddShield(int value): value(value){};