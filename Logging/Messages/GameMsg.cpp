#include "GameMsg.h"

GameMsg::GameMsg(std::string msg) {
    this->msg = msg;
}

std::string GameMsg::get_msg() {
    return msg;
}

std::ostream &operator<<(std::ostream &out, GameMsg* msg) {
    out << msg->get_msg();
    return out;
}
