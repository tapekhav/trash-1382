#ifndef LABS_EVENTFIELD_H
#define LABS_EVENTFIELD_H


#include "../../Background/Field.h"

class EventField : public Event {
public:
    void execute() override = 0;
protected:
    Field* field;
};

#endif
