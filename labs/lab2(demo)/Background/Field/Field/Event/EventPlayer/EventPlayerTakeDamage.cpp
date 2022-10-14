
#include "EventPlayerTakeDamage.h"

EventPlayerTakeDamage::EventPlayerTakeDamage(int value): value(value){}

void EventPlayerTakeDamage::changeSpecification(Player* player) {
    player->takeDamage(value);
}