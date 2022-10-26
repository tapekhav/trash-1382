//
// Created by corvussharp on 26.10.22.
//

#include "ConsoleOutput.h"

Output &ConsoleOutput::operator<<(std::string message) {
    std::cout<<message;
    return *this;
}
