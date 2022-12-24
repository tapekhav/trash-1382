//
// Created by corvussharp on 01.10.22.
//

#ifndef UNTITLED48_EVENTXP_H
#define UNTITLED48_EVENTXP_H

#include "EventPerson.h"
//#include "../../Persons/Person.h"
class EventXp:public EventPerson {
public:

    bool execute(void *obj) override;


EventXp(Person* person);

//~EventXp() override;
};


#endif //UNTITLED48_EVENTXP_H
