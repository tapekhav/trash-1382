#pragma once
#include "Message.h"
#include <map>
class Log{
    private:
        std::map <MessageLevel, bool> out_info;
        MessageLevel current_level = none;
    protected:
        Message pref(MessageLevel ml);
    public:
        virtual void out_message(Message messege) = 0;
        void set_out_info(MessageLevel ml, bool b);
        bool get_out_info(MessageLevel ml);
};