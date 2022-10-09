#include "EventPlayerDownHealth.h"

EventPlayerDownHealth::EventPlayerDownHealth(int value): value(value){};

void EventPlayerDownHealth::callReaction(std::shared_ptr<Player> player){
    EventPlayerDownHealth::changeSpecification(player);
};
void EventPlayerDownHealth::changeSpecification(std::shared_ptr<Player> player){
    player->downHealth(value);
};
