//
// Created by corvussharp on 12.10.22.
//

#include "EventChangeField.h"

#include "../../Field/Field.h"

void EventChangeField::change_map(Field *field) {
    field->spawn_events();
    notify();
}

