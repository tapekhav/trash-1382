#ifndef SURVIVAL_EVENT_H
#define SURVIVAL_EVENT_H

#include "Enums.h"

#include "Logging/Subject.h"
#include "Logging/Message.h"
#include "Logging/Messages/StatusDecorator.h"

class Event : public Subject{
public:
    virtual bool Happen() = 0;
    virtual EnumClass::Events GetStatus() = 0;
    virtual ~Event() {}
};

#endif //SURVIVAL_EVENT_H