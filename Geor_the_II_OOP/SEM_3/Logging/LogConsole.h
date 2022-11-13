#pragma once
#include "Log.h"
#include <iostream>
class LogConsole : public Log{
    public:
        virtual void out_message(Message messege);
};