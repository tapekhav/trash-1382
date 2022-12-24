//
// Created by corvussharp on 06.10.22.
//

#ifndef UNTITLED48_EVENTDMG_H
#define UNTITLED48_EVENTDMG_H

#include "EventPerson.h"
//#include "../../Persons/Person.h"


class EventDmg: public EventPerson{
public:

    bool execute(void *obj) override;

    EventDmg(Person* person);
};

#endif //UNTITLED48_EVENTDMG_H
