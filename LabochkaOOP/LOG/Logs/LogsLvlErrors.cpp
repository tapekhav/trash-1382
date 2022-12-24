//
// Created by corvussharp on 28.10.22.
//

#include "LogsLvlErrors.h"

void LogsLvlErrors::update(Message &msg) {
    if (msg.getType() == ERROR) {
        Logger::getInstance().print(msg);
    }
}

LogsLvlErrors::LogsLvlErrors(Subject *model) {
    {
        model->attach(this);
    }
}