//
// Created by corvussharp on 01.10.22.
//

#ifndef UNTITLED48_EVENTXP_H
#define UNTITLED48_EVENTXP_H
#include "EventPerson.h"
#include "../../Persons/Person.h"

class EventXp:public EventPerson {
public:
void change_stats(Person* person) override;
//~EventXp() override;
};


#endif //UNTITLED48_EVENTXP_H
