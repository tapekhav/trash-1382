#ifndef LABS_EVENT_H
#define LABS_EVENT_H

class Event {
public:
    virtual void execute() = 0;
    //virtual ~Event() = default;
};

#endif
