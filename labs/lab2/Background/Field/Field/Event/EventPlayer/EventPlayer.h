#ifndef LAB2_EVENTPLAYER_H
#define LAB2_EVENTPLAYER_H


#include "../Event.h"

class EventPlayer: public Event {
    virtual void changeSpecification(std::shared_ptr<Player> player) = 0;
};


#endif
