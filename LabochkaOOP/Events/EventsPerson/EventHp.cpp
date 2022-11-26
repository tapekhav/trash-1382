//
// Created by corvussharp on 06.10.22.
//

#include "EventHp.h"
 bool EventHp::execute(void *obj) {
     if (person) {
         person->set_hp(person->get_hp() + 5);
         Message message(GAME, "Heal event happened");
         LOG.print(message);
         return true;
     } return false;
 }

EventHp::EventHp(Person *person) {
    this->person = person;
}
