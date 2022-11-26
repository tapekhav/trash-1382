//
// Created by corvussharp on 21.09.22.
//


#ifndef UNTITLED48_EVENTPERSON_H
#define UNTITLED48_EVENTPERSON_H
class Field;
class Person;
class Event;
class EventXp;
#include "../../Persons/Person.h"
#include "../Event.h"

class EventPerson: public Event{
public:
    virtual bool execute(void *obj) = 0;

    virtual ~EventPerson() = default;

protected:
    Person* person{};
};


#endif //UNTITLED48_EVENTPERSON_H
