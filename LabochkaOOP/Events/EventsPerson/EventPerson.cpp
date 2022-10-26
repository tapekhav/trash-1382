//
// Created by corvussharp on 21.09.22.
//

#include "EventPerson.h"

void EventPerson::doing(void* obj){
    change_stats((Person*) obj);
    notify();
}