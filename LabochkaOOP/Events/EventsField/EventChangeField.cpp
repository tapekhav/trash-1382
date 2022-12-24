//
// Created by corvussharp on 12.10.22.
//

#include "EventChangeField.h"


EventChangeField::EventChangeField(Field *field) {
    this->field = field;
}

bool EventChangeField::execute(void *obj) {
    if (field) {
        field->spawn_events();
        Message message(GAME, "Change event happened");
        notify(message);
        return true;
    }
    return false;
}
