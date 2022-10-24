#include "InputMsg.h"

InputMsg::InputMsg(std::string msg) {
    this->msg = msg;
}

std::string InputMsg::get_msg() {
    return msg;
}

std::ostream &operator<<(std::ostream& out, InputMsg* msg) {
    out << msg->get_msg();
    return out;
}
