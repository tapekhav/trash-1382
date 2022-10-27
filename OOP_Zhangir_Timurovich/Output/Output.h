//
// Created by roman on 26.10.2022.
//

#ifndef MAIN_CPP_OUTPUT_H
#define MAIN_CPP_OUTPUT_H

class Message;

#include <string>
#include "../Logging/Message.h"

class Output {
public:
    virtual ~Output() = default;

    virtual void print(Message &message) = 0;
};


#endif //MAIN_CPP_OUTPUT_H
