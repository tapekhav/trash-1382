//
// Created by corvussharp on 07.11.22.
//

#ifndef LABOCHKAOOP_CONTROLCONFIG_H
#define LABOCHKAOOP_CONTROLCONFIG_H

#include "../LOG/LogsInfo/Structs.h"
#include "map"
#include <fstream>
#include "sstream"
#include "vector"


class ControlConfig {
public:
    virtual void read_config() = 0;
    virtual CONTROL get_key(char key) = 0;
    virtual void check_fix_config() = 0;

};

#endif //LABOCHKAOOP_CONTROLCONFIG_H
