//
// Created by corvussharp on 26.10.22.
//

#ifndef LABOCHKAOOP_OUTPUT_H
#define LABOCHKAOOP_OUTPUT_H
#include "iostream"

class Output {
public:
    virtual ~Output() = default;
    virtual Output &operator<<(std::string message) = 0;
};




#endif //LABOCHKAOOP_OUTPUT_H
