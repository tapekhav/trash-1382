//
// Created by roman on 26.10.2022.
//

#ifndef MAIN_CPP_MESSAGE_H
#define MAIN_CPP_MESSAGE_H

class LogOutInfo;

#include <ostream>
#include <string>
#include "../Info/Structs.h"
#include "../Info/LogOutInfo.h"

class Message {
public:
    Message(LEVEL type, const std::string &message, LogOutInfo *info);

    LEVEL getType();

    std::string get_message();

    LogOutInfo *get_info();

    friend std::ostream &operator<<(std::ostream &os, Message &message);

private:
    LEVEL type;
    std::string message;
    LogOutInfo *info;
};


#endif //MAIN_CPP_MESSAGE_H
