
#include "WallVertType.h"

bool WallVertType::get_pass() {
    return this->pass;
}

//Event *WallVertType::get_event() {
//    return this->event;
//}

WallVertType::WallVertType() {
    this->pass = true;
//    this->event = nullptr;
}