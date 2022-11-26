
//
// Created by corvussharp on 28.10.22.
//

#ifndef LABOCHKAOOP_MESSAGE_H
#define LABOCHKAOOP_MESSAGE_H

class LogOutInfo;

#include "iostream"
#include "../LogsInfo/Structs.h"
#include "../LogsInfo/LogOutInfo.h"


class Message {
public:
    Message(LEVEL type, std::string message);

    LEVEL getType();

    std::string get_message();

    std::string get_pref();

    friend std::ostream &operator<<(std::ostream &os, Message &message);

private:
    LEVEL type;
    std::string message;
    std::string pref;
};


#endif //LABOCHKAOOP_MESSAGE_H
