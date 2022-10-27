#ifndef OOP_LOGGER_H
#define OOP_LOGGER_H

#include "../Info/LogOutInfo.h"
#include "Message.h"
#include <vector>
#include "../Output/Output.h"

class Logger {
public:
    Logger(LogOutInfo* info);
    void print(Message &message);

private:
    std::vector<Output *> outs;
};


#endif //OOP_LOGGER_H
