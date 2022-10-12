#include "IncreaseType.h"

bool IncreaseType::get_pass() {
    return this->pass;
}

//Event* IncreaseType::get_event() {
//    return this->event;
//}

IncreaseType::IncreaseType() {
    this->pass = true;
//    this->event = new Increase;
}