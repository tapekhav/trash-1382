#ifndef LABS_EVENT_H
#define LABS_EVENT_H


#include "../Characters/Player.h"

class Event{
public:
    Event() = default;
    virtual void execute(Player& player) = 0;
    virtual ~Event() = 0;
};

#endif //LABS_EVENT_H
