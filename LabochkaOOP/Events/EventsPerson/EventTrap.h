//
// Created by corvussharp on 14.10.22.
//

#ifndef LABOCHKAOOP_EVENTTRAP_H
#define LABOCHKAOOP_EVENTTRAP_H

#include "EventPerson.h"
class EventTrap: public EventPerson{

public:
    void change_stats(Person *person) override;
   // ~EventTrap() override;
};


#endif //LABOCHKAOOP_EVENTTRAP_H
