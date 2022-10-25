//
// Created by corvussharp on 14.10.22.
//

#include "EventTrap.h"
    void EventTrap::change_stats(Person *person) {
        person->set_hp(person->get_hp()-5);
    }
