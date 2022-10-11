#ifndef LAB2_EVENTPLAYER_H
#define LAB2_EVENTPLAYER_H


#include "../Event.h"

class EventPlayer: public Event {
    void callReaction(void*) override;
    virtual void changeSpecification(Player*) = 0;
};


#endif
