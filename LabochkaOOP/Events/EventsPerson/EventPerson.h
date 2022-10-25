//
// Created by corvussharp on 21.09.22.
//


#ifndef UNTITLED48_EVENTPERSON_H
#define UNTITLED48_EVENTPERSON_H
#include "../../Persons/Person.h"
#include "../../Events/Events.h"


class EventPerson: public Event{
public:
    void doing(void*) override;
    virtual void change_stats(Person* person) = 0;
    virtual ~EventPerson() = default;


};


#endif //UNTITLED48_EVENTPERSON_H
