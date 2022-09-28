#ifndef LABS_EVENT_H
#define LABS_EVENT_H


#include "../Characters/Player.h"

class Event{
public:
    virtual void execute(Player& player) = 0;
    virtual ~Event() = default;
};

#endif //LABS_EVENT_H
