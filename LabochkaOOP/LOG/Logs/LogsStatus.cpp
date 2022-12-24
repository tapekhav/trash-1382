//
// Created by corvussharp on 28.10.22.
//

#include "LogsStatus.h"

void LogsStatus::update(Message &msg) {
    if (msg.getType() == STATUS) {
        Logger::getInstance().print(msg);
    }
}

LogsStatus::LogsStatus(Subject *model) {
    model->attach(this);
}