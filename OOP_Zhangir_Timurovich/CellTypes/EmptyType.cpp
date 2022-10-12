
#include "EmptyType.h"

bool EmptyType::get_pass() {
    return this->pass;
}

//Event *EmptyType::get_event() {
//    return this->event;
//}

EmptyType::EmptyType() {
    this->pass = true;
//    this->event = nullptr;
}