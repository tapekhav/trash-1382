//
// Created by corvussharp on 06.10.22.
//

#ifndef UNTITLED48_EVENTFIELD_H
#define UNTITLED48_EVENTFIELD_H

#include "../Events.h"

class Field;

class EventField: public Event{
public:
    void doing(void*) override;
    virtual void change_map(Field* field) = 0;
};

#endif //UNTITLED48_EVENTFIELD_H
