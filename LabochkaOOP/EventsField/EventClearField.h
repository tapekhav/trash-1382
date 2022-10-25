//
// Created by corvussharp on 10.10.22.
//

#ifndef LABOCHKAOOP_EVENTCLEARFIELD_H
#define LABOCHKAOOP_EVENTCLEARFIELD_H

#include "EventField.h"
class EventClearField:public EventField {
public:
    void execute(Field& field) override ;
};


#endif //LABOCHKAOOP_EVENTCLEARFIELD_H
