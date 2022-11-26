
//
// Created by corvussharp on 28.10.22.
//

#ifndef LABOCHKAOOP_LOGGER_H
#define LABOCHKAOOP_LOGGER_H

#define LOG Logger::getInstance()

#include "../LogsInfo/LogOutInfo.h"
#include "../OutPut/ConsoleOut.h"
#include "../OutPut/FileOut.h"

class Logger {
public:
    void print(Message &message);
    void setLogOutInfo(const LogOutInfo &info);

    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    static Logger &getInstance();

private:
    Logger() = default;

    std::vector<Output *> outs;
};


#endif //LABOCHKAOOP_LOGGER_H
