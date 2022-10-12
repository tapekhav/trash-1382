

#include "CollapseType.h"

bool CollapseType::get_pass() {
    return this->pass;
}

//Event* CollapseType::get_event() {
//    return this->event;
//}

CollapseType::CollapseType() {
    this->pass = true;
//    this->event = new Collapse;
}