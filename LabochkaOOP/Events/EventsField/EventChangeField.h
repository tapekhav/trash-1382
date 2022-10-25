//
// Created by corvussharp on 12.10.22.
//

#ifndef LABOCHKAOOP_EVENTCHANGEFIELD_H
#define LABOCHKAOOP_EVENTCHANGEFIELD_H


#include "EventField.h"

class EventChangeField : public EventField {
public:
    void change_map(Field *field) override;
};


#endif //LABOCHKAOOP_EVENTCHANGEFIELD_H
