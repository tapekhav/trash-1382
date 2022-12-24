//
// Created by corvussharp on 06.10.22.
//

#include "EventDmg.h"
bool EventDmg::execute(void *obj) {
    if (person) {
        person->set_dmg(person->get_dmg() + 18);
        Message message(GAME, "Dmg event happened");
        LOG.print(message);
        return true;
    }
    return false;
}

EventDmg::EventDmg(Person *person) {
    this->person = person;
}





//EventDmg::~EventDmg() = default;
