//
// Created by corvussharp on 28.10.22.
//

#ifndef LABOCHKAOOP_LOGSSTATUS_H
#define LABOCHKAOOP_LOGSSTATUS_H


#include "Observer.h"
#include "Subject.h"

class LogsStatus : public Observer {
public:
    LogsStatus(Subject *model);

    void update(Message &msg) override;
};


#endif //LABOCHKAOOP_LOGSSTATUS_H
