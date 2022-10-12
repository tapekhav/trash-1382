#ifndef LABS_EVENTPLAYER_H
#define LABS_EVENTPLAYER_H

#include "../../Characters/Player.h"
#include "../Event.h"

class EventPlayer : public Event {
public:
    virtual void execute(Player& player) = 0;
    virtual ~EventPlayer() = default;
};

#endif
