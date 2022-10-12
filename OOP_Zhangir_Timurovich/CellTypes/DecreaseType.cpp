
#include "DecreaseType.h"

bool DecreaseType::get_pass() {
    return this->pass;
}

//Event* DecreaseType::get_event() {
//    return this->event;
//}

DecreaseType::DecreaseType() {
    this->pass = true;
//    this->event = new Decrease;
}