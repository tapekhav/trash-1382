#include "WallHorType.h"

bool WallHorType::get_pass() {
    return this->pass;
}

//Event *WallHorType::get_event() {
//    return this->event;
//}

WallHorType::WallHorType() {
    this->pass = true;
//    this->event = nullptr;
}