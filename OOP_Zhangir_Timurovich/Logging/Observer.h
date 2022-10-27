#ifndef MAIN_CPP_OBSERVER_H
#define MAIN_CPP_OBSERVER_H
#include "Message.h"
#include "../Logging/Logger.h"

class Observer {
public:
    virtual void update(Message &msg) = 0;
    virtual ~Observer() {};
};


#endif //MAIN_CPP_OBSERVER_H
