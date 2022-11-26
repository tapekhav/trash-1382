//
// Created by corvussharp on 22.11.22.
//

#ifndef LABOCHKAOOP_COMMANDREAD_H
#define LABOCHKAOOP_COMMANDREAD_H

#include "../LOG/LogsInfo/Structs.h"
#include "iostream"
#include "../INPUT/ControlConfig.h"
#include "../INPUT/ControlFile.h"

class CommandRead {
public:

    virtual CONTROL read_step() = 0;
    virtual ~CommandRead() = default;
protected:
    ControlConfig *control_config;
};


#endif //LABOCHKAOOP_COMMANDREAD_H
