#ifndef LAB2_EVENT_H
#define LAB2_EVENT_H


#include <memory>
#include "../../../../Characters/Player.h"

class Event {
public:
    virtual ~Event() = default;
    virtual void callReaction(std::shared_ptr<Player>) = 0;
};


#endif
