//
// Created by corvussharp on 28.10.22.
//

#include "LogsLvlGame.h"

void LogsLvlGame::update(Message &msg) {
    if (msg.getType() == GAME) {
        Logger::getInstance().print(msg);
    }
}

LogsLvlGame::LogsLvlGame(Subject *model) {
    model->attach(this);
}
