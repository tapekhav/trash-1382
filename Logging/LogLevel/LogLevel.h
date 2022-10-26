#ifndef LABS_LOGTYPE_H
#define LABS_LOGTYPE_H

#include <string>
#include "Messages/Message.h"
#include "../Logger/Logger.h"

class LogLevel {
public:
    virtual void update(Logger*, const Message &message) = 0;
};


#endif
