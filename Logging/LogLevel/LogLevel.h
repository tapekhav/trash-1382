#ifndef LABS_LOGTYPE_H
#define LABS_LOGTYPE_H

#include <string>
#include <vector>
#include "Messages/Message.h"
#include "../Logger/Logger.h"

class LogLevel {
public:
    virtual void update(Message &message) = 0;
    virtual void set_loggers(std::vector<Logger*>&) = 0;
protected:
    std::vector<Logger*> loggers;
};


#endif
