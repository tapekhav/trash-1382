#include "EventPlayerAddHealth.h"

EventPlayerAddHealth::EventPlayerAddHealth(int value): value(value){};

void EventPlayerAddHealth::changeSpecification(Player* player) {
    player->addHealth(value);
}

