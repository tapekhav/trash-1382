#ifndef GAME_IEVENTPLAYER_H
#define GAME_IEVENTPLAYER_H

#include <memory>
#include "../Event.h"


class IEventPlayer: public Event{
    virtual void changeSpecification(std::shared_ptr<Player> player) = 0;
};

#endif
