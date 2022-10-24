#ifndef LABS_CONSOLELOG_H
#define LABS_CONSOLELOG_H

#include "Logger/Logger.h"

class ConsoleLog : public Logger {
public:
    void print(Message*) override;
};


#endif
