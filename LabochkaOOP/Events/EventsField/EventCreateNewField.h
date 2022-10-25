//
// Created by corvussharp on 11.10.22.
//

#ifndef LABOCHKAOOP_EVENTCREATENEWFIELD_H
#define LABOCHKAOOP_EVENTCREATENEWFIELD_H

#include "../../Field/Field.h"

class EventCreateNewField:EventField {
public:
    void change_map(Field* field) override;
};


#endif //LABOCHKAOOP_EVENTCREATENEWFIELD_H
