//
// Created by corvussharp on 26.10.22.
//

#include "LogsLvlErrors.h"

LogsLvlErrors::LogsLvlErrors(Subject *model) {
    model->attach(this);
}

void LogsLvlErrors::update() {

}
