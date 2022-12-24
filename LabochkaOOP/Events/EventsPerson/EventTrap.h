//
// Created by corvussharp on 14.10.22.
//

#ifndef LABOCHKAOOP_EVENTTRAP_H
#define LABOCHKAOOP_EVENTTRAP_H
//#include "../../Persons/Person.h"

#include "EventPerson.h"
class EventTrap: public EventPerson{

public:
    EventTrap(Person* person);
    bool execute(void *obj) override;

};


#endif //LABOCHKAOOP_EVENTTRAP_H
