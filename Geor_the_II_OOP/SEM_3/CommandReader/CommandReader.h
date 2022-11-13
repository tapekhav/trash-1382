#pragma once
#include "CommandOperand.h"
#include <string>
class CommandReader{
    public:
        virtual CommandOperand get_command() = 0;
        virtual std::string get_symbol(CommandOperand co) = 0;
};