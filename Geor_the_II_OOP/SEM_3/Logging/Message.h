#pragma once
#include "MessageLevel.h"
#include <string>
#include <ostream>
class Message{
    private:
        std::string text;
        MessageLevel level;
    public:
        Message(std::string t, MessageLevel l);
        void set_text(std::string t);
        void set_level(MessageLevel l);
        std::string get_text();
        MessageLevel get_level();
        //std::ostream &operator<<(std::ostream &os);
        friend std::ostream &operator<<(std::ostream &os, Message &message);
};