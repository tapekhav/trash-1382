//
// Created by corvussharp on 06.10.22.
//

#ifndef UNTITLED48_EVENTFIELD_H
#define UNTITLED48_EVENTFIELD_H

#include "../Field/Field.h"

class EventField {
public:
    virtual void execute(Field& field) = 0;
    virtual ~EventField() = default;
};

#endif //UNTITLED48_EVENTFIELD_H
