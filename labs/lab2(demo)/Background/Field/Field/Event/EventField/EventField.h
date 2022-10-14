#ifndef LAB2_EVENTFIELD_H
#define LAB2_EVENTFIELD_H

class Field;
#include <string>
#include "../Event.h"

class EventField: public Event {
    void callReaction(void*) override;
    virtual void changeField(Field*) = 0;
};


#endif