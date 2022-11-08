//
// Created by roman on 26.10.2022.
//

#include "Logger.h"
#include "../Info/Enums.h"
#include "../Output/FileOut.h"
#include "../Output/ConsoleOut.h"

void Logger::print(Message &msg) {
    for (auto elem: outs) {
        elem->print(msg);
    }
}

Logger::Logger(LogOutInfo *info) {
    for (auto elem: info->get_outputs()) {
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
