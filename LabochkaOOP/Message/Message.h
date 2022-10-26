//
// Created by corvussharp on 26.10.22.
//

#ifndef LABOCHKAOOP_MESSAGE_H
#define LABOCHKAOOP_MESSAGE_H

#include "iostream"

class Message {
public:
    virtual std::string get_message(int key) = 0;
};



#endif //LABOCHKAOOP_MESSAGE_H
