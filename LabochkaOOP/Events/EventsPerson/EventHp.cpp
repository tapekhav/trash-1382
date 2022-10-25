//
// Created by corvussharp on 06.10.22.
//

#include "EventHp.h"
 void EventHp::change_stats(Person* person) {
     person->set_hp(person->get_hp()+5);
    }
