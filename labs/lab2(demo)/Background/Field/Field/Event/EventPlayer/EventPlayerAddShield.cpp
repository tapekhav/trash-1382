#include "EventPlayerAddShield.h"

EventPlayerAddShield::EventPlayerAddShield(int value): value(value){};

void EventPlayerAddShield::changeSpecification(Player* player) {
    player->addShield(value);
}
