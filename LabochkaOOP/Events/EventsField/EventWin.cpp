//
// Created by corvussharp on 11.10.22.
//

#include "EventWin.h"


EventWin::EventWin(Field *field) {
    this->field = field;
}

bool EventWin::execute(void *obj) {
    if (field) {
        field->trig_win();
        Message message(GAME, "Win event happened");
        notify(message);
        return true;
    }
    return false;
}

