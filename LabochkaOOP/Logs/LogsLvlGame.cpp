//
// Created by corvussharp on 26.10.22.
//
#include "iostream"
#include "LogsLvlGame.h"
LogsLvlGame::LogsLvlGame(Subject &model) {
    model.attach(this);
}

void LogsLvlGame::update() {
    puts("NEGRIPIDORASI!!!!!!!!!!!!!!!!!!!!");
}
