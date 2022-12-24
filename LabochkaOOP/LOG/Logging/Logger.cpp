//
// Created by corvussharp on 28.10.22.
//

#include "Logger.h"


void Logger::print(Message &msg) {
    for (auto elem: outs) {
        elem->print(msg);
    }
}

Logger &Logger::getInstance() {
    static Logger logger;
    return logger;
}

void Logger::setLogOutInfo(const LogOutInfo &info) {
    for (auto elem: info.get_outputs()) {
        switch (elem) {
            case FILEOUT:
                outs.push_back(new FileOut("logs.txt"));
                break;
            case CONSOLE:
                outs.push_back(new ConsoleOut);
                break;
        }
    }
}
