//
// Created by roman on 12.10.2022.
//

#include "StoneType.h"

bool StoneType::get_pass() {
    return this->pass;
}

//Event *StoneType::get_event() {
//    return this->event;
//}

StoneType::StoneType() {
    this->pass = false;
//    this->event = nullptr;
}