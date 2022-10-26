//
// Created by corvussharp on 26.10.22.
//

#ifndef LABOCHKAOOP_CONSOLEOUTPUT_H
#define LABOCHKAOOP_CONSOLEOUTPUT_H
#include "Output.h"

class ConsoleOutput: public Output{
Output &operator<<(std::string message) override;
};


#endif //LABOCHKAOOP_CONSOLEOUTPUT_H
