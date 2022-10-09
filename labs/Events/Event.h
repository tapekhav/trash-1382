#ifndef LABS_EVENT_H
#define LABS_EVENT_H

#include "./ChangePlayer/EventPlayer.h"

class Event {
public:
    virtual void execute() = 0;
    virtual ~Event() = default;
};

#endif
