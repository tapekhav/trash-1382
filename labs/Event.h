#ifndef LABS_EVENT_H
#define LABS_EVENT_H

class Event{
public:
    Event() = default;
    virtual void execute() = 0;
    virtual ~Event() = 0;
};

#endif //LABS_EVENT_H
