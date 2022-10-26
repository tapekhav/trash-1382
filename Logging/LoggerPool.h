#ifndef LABS_LOGGERPOOL_H
#define LABS_LOGGERPOOL_H

#include <vector>
#include <algorithm>
#include "LogLevel/LogLevel.h"
#include "Logger/Logger.h"

class LoggerPool {
public:
    explicit LoggerPool(Logger* log);
    ~LoggerPool();

    template<typename T>
    void attach() {
        if (std::is_base_of<LogLevel, T>::value)
            levels.push_back(new T);
    }

    template<typename T>
    void attach(const std::string& name) {
        if (std::is_base_of<LogLevel, T>::value)
            levels.push_back(new T(name));
    }

    void proceed(Message&);
private:
    std::vector<Logger*> loggers;
    std::vector<LogLevel*> levels;
};


#endif
