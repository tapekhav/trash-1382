#include "EventPlayerDownShield.h"

EventPlayerDownShield::EventPlayerDownShield(int value): value(value) {};

void EventPlayerDownShield::callReaction(std::shared_ptr<Player> player){
    EventPlayerDownShield::changeSpecification(player);
};
void EventPlayerDownShield::changeSpecification(std::shared_ptr<Player> player){
    player->downShield(value);
};