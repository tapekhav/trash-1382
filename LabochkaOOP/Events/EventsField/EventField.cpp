//
// Created by corvussharp on 06.10.22.
//

#include <string>
#include "EventField.h"
void EventField::doing(void* obj){
    change_map((Field *) obj);
    notify();
}