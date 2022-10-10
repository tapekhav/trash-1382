#ifndef LABS_EVENTFIELD_H
#define LABS_EVENTFIELD_H

class Field;

#include "../../Background/Field.h"

class EventField : public Event {
public:
    virtual void execute(Field& field) = 0;
    void execute() override {};
    virtual ~EventField() = default;
};


#endif
