#include "EventPlayer.h"


void EventPlayer::callReaction(void *obj) {
    auto* player = (Player*) obj;
    changeSpecification(player);
}