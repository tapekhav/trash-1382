//
// Created by roman on 26.10.2022.
//

#include "Message.h"


Message::Message(LEVEL type, const std::string &message, LogOutInfo *info) {
    this->message = message;
    this->type = type;
    this->info = info;
}

std::string Message::get_message() {
    return this->message;
}

LEVEL Message::getType() {
    return this->type;
}

LogOutInfo *Message::get_info() {
    return this->info;
}

std::ostream &operator<<(std::ostream &os, Message &message) {
    os << message.get_message();
    os << std::endl;
    return os;
}
