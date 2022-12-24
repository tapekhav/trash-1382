//
// Created by corvussharp on 12.10.22.
//

#ifndef LABOCHKAOOP_EVENTCHANGEFIELD_H
#define LABOCHKAOOP_EVENTCHANGEFIELD_H

class Field;

#include "../../Field/Field.h"
#include "EventField.h"

class EventChangeField : public EventField {
public:
    bool execute(void *obj) override;

    explicit EventChangeField(Field *field);
};


#endif //LABOCHKAOOP_EVENTCHANGEFIELD_H
