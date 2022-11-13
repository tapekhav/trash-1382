#pragma once
#include "CommandReader.h"
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
class CommandReaderKeyboard : public CommandReader{
    private:
        std::vector <std::pair<CommandOperand, char>> setting;
    public:
        CommandReaderKeyboard(std::string file_name);
        CommandReaderKeyboard();
        virtual CommandOperand get_command();
        virtual std::string get_symbol(CommandOperand co);
};