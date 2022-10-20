#ifndef SURVIVAL_EVENT_H
#define SURVIVAL_EVENT_H

#include "Enums.h"

class Event {
public:
    virtual bool Happen() = 0;
    virtual EnumClass::Events GetStatus() = 0;
};

#endif //SURVIVAL_EVENT_H