//
// Created by roman on 26.10.2022.
//

#ifndef MAIN_CPP_MESSAGE_H
#define MAIN_CPP_MESSAGE_H

#include <string>
#include "../Info/Structs.h"

class Message {
public:
    Message(LEVEL type, const std::string &message);

    LEVEL getType();

    std::string get_message();

private:
    LEVEL type;
    std::string message;
};


#endif //MAIN_CPP_MESSAGE_H
