//
// Created by corvussharp on 06.10.22.
//

#ifndef UNTITLED48_EVENTDMG_H
#define UNTITLED48_EVENTDMG_H
#include "EventPerson.h"
#include "../../Persons/Person.h"

class EventDmg: public EventPerson{
public:
    void change_stats(Person* person) override;
   // ~EventDmg() override;
};

#endif //UNTITLED48_EVENTDMG_H
