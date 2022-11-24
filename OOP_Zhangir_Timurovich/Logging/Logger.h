#ifndef OOP_LOGGER_H
#define OOP_LOGGER_H

#include "../Info/LogOutInfo.h"
#include "Message.h"
#include <vector>
#include "../Output/Output.h"
#define LOG Logger::getInstance()

class Logger {
public:

    void print(Message &message);

    Logger(const Logger &) = delete;

    Logger &operator=(const Logger &) = delete;

    static Logger &getInstance();

    void setLogOutInfo(LogOutInfo *info);

private:
    Logger() = default;

    std::vector<Output *> outs;
};


#endif //OOP_LOGGER_H
