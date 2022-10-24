#ifndef LABS_EVENT_H
#define LABS_EVENT_H
#include "../Logging/Observable.h"

class Event : public Observable {
public:
    virtual void execute() = 0;
    virtual ~Event() = default;
};

#endif
