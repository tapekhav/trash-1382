#include "EventMsg.h"

EventMsg::EventMsg(std::string msg) {
    this->msg = msg;
}

std::string EventMsg::get_msg() {
    return msg;
}

std::ostream &operator<<(std::ostream &out, EventMsg* msg) {
    out << msg->get_msg();
    return out;
}
