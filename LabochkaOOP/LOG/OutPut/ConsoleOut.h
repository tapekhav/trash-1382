//
// Created by corvussharp on 28.10.22.
//

#ifndef LABOCHKAOOP_CONSOLEOUT_H
#define LABOCHKAOOP_CONSOLEOUT_H


#include <string>
#include <iostream>
#include "Output.h"

class ConsoleOut : public Output {
public:
    void print(Message &message) override;

    ConsoleOut() = default;
};


#endif //LABOCHKAOOP_CONSOLEOUT_H
