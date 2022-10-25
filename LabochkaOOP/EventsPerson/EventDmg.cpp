//
// Created by corvussharp on 06.10.22.
//

#include "EventDmg.h"
void EventDmg::doing(Person &person) {
    person.set_dmg(person.get_dmg()+18);
}