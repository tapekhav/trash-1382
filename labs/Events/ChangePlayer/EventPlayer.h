#ifndef LABS_EVENTPLAYER_H
#define LABS_EVENTPLAYER_H

#include "../../Characters/Player.h"

class EventPlayer {
public:
    virtual void execute(Player& player) = 0;
    virtual ~EventPlayer() = default;
};

#endif
