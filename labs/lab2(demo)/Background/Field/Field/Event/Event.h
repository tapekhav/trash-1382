#ifndef LAB2_EVENT_H
#define LAB2_EVENT_H

#include "string"


class Event {
public:
    virtual ~Event() = default;
    virtual void callReaction(void*) = 0;
};


#endif
