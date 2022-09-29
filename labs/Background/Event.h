#ifndef GAME_EVENT_H
#define GAME_EVENT_H


#include "../Characters/Player.h"

class Event {
public:
    virtual void callReaction() = 0;
};

#endif
