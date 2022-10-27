//
// Created by roman on 26.10.2022.
//

#include "Message.h"


Message::Message(LEVEL type, std::string message, LogOutInfo *info) {
    switch (type) {
        case GAME:
            this->pref = "[GAME]";
            break;
        case ERROR:
            this->pref = "[ERROR]";
            break;
        case STATUS:
            this->pref = "[STATUS]";
            break;
    }

    this->message = message;
    this->type = type;
    this->info = info;
}

std::string Message::get_message() {
    return this->message;
}

std::string Message::get_pref() {
    return this->pref;
}

LEVEL Message::getType() {
    return this->type;
}

LogOutInfo *Message::get_info() {
    return this->info;
}

std::ostream &operator<<(std::ostream &os, Message &message) {
    os << message.get_pref() << ' ';
    os << message.get_message();
    os << std::endl;
    return os;
}
