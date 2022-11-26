//
// Created by corvussharp on 28.10.22.
//

#ifndef LABOCHKAOOP_LOGSLVLERRORS_H
#define LABOCHKAOOP_LOGSLVLERRORS_H

#include "Subject.h"
#include "Observer.h"

class LogsLvlErrors : public Observer {
public:
    LogsLvlErrors(Subject *model);

    void update(Message &msg) override;
};

#endif //LABOCHKAOOP_LOGSLVLERRORS_H
