
#include "PlayerType.h"

bool PlayerType::get_pass() {
    return this->pass;
}

//Event *PlayerType::get_event() {
//    return this->event;
//}

PlayerType::PlayerType() {
    this->pass = true;
//    this->event = nullptr;
}