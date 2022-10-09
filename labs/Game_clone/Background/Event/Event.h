#ifndef GAME_EVENT_H
#define GAME_EVENT_H


#include "../../Characters/Player.h"
#include <memory>

class Event {
public:
    virtual ~Event() = default;
    virtual void callReaction(std::shared_ptr<Player> player) = 0;
};

#endif
