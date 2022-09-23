#ifndef GAME_EVENT_H
#define GAME_EVENT_H


#include "Player.h"

class Event {
public:
    virtual void callReaction(Player& player) = 0;
};


#endif
