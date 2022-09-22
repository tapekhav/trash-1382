#ifndef SURVIVAL_EVENT_H
#define SURVIVAL_EVENT_H

class Event {
    virtual void HandleEvent() = 0;
    virtual ~Event() = 0;
};

#endif //SURVIVAL_EVENT_H