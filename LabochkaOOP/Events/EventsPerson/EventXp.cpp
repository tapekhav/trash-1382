//
// Created by corvussharp on 01.10.22.
//

#include "EventXp.h"
bool EventXp::execute(void *obj) {
    if(person) {
        person->set_xp(person->get_xp() + 100);
        if (person->get_xp() > 150) {
            person->set_lvl(person->get_lvl() + 1);
            person->set_xp(person->get_xp() - 150);
        }
        Message message(GAME, "XP event happened");
        LOG.print(message);
//        notify(message);
        return true;
    } return false;
}

EventXp::EventXp(Person *person) {
    this->person = person;
}






