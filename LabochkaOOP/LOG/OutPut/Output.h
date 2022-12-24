//
// Created by corvussharp on 28.10.22.
//

#ifndef LABOCHKAOOP_OUTPUT_H
#define LABOCHKAOOP_OUTPUT_H

class Message;

#include <string>
#include "../Logging/Message.h"


class Output {
public:
    virtual ~Output() = default;

    virtual void print(Message &message) = 0;
};


#endif //LABOCHKAOOP_OUTPUT_H
