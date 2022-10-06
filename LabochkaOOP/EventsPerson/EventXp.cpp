//
// Created by corvussharp on 01.10.22.
//

#include "EventXp.h"
void EventXp::doing(Person& person) {
    person.set_xp(person.get_xp() + 100);
    if (person.get_xp() > 150) {
        person.set_lvl(person.get_lvl() + 1);
        person.set_xp(person.get_xp() - 150);
    }
}

