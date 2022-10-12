
#include "HealType.h"

bool HealType::get_pass() {
    return this->pass;
}

//Event *HealType::get_event() {
//    return this->event;
//}

HealType::HealType() {
    this->pass = true;
//    this->event = new Heal;
}