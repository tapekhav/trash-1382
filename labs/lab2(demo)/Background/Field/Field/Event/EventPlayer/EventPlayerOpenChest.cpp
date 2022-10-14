#include <iostream>
#include "EventPlayerOpenChest.h"

EventPlayerOpenChest::EventPlayerOpenChest(int value): value(value){};

void EventPlayerOpenChest::changeSpecification(Player* player) {
    if (player->getCoins() >= value){
        player->addHealth(value);
        player->downCoins(value);
    }
}
