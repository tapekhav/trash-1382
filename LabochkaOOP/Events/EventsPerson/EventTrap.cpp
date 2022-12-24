//
// Created by corvussharp on 14.10.22.
//

#include "EventTrap.h"
    bool EventTrap::execute(void *obj) {
        if (person) {
            person->set_hp(person->get_hp() - 5);
            Message message(GAME, "Trap event happened");
            LOG.print(message);
            return true;
        } return false;
    }

EventTrap::EventTrap(Person *person) {
    this->person = person;
}

