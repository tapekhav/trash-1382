//
// Created by corvussharp on 06.10.22.
//

#ifndef UNTITLED48_EVENTFIELD_H
#define UNTITLED48_EVENTFIELD_H

#include "../Event.h"

class Field;

class EventField : public Event {
public:
    bool execute(void *obj) override = 0;

protected:
    Field *field{};
};

#endif //UNTITLED48_EVENTFIELD_H
