#ifndef GAME_TRAPEVENT_H
#define GAME_TRAPEVENT_H

#include "Event.h"
#include "Player.h"


class TrapEvent: public Event{
public:
    TrapEvent() = default;
    void cellReaction(Player& player);
};


#endif
