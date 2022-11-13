#pragma once
#include "Log.h"
#include <fstream>
#include <string.h>
class LogFile : public Log{
    private:
        std::ofstream out;
    public:
        LogFile(std::string file_name);
        virtual void out_message(Message message);
        ~LogFile();
};