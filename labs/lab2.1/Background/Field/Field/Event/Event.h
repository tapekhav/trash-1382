#ifndef LAB2_EVENT_H
#define LAB2_EVENT_H


#include <memory>
#include "../../../../Characters/Player.h"

class Event {
public:
    virtual ~Event() = default;
    virtual void callReaction(void*) = 0;
};


#endif
