//
// Created by roman on 26.10.2022.
//

#include "Message.h"

Message::Message(LEVEL type, const std::string &message) {
    this->message = message;
    this->type = type;
}

std::string Message::get_message(){
    return this->message;
}

LEVEL Message::getType(){
    return this->type;
}
