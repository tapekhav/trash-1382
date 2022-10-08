#ifndef LABS_EVENTFIELD_H
#define LABS_EVENTFIELD_H

#include "../../Background/Field.h"

class EventField {
public:
    virtual void execute(Field& field) = 0;
    EventField() = default;
    virtual ~EventField() = default;
};


#endif
