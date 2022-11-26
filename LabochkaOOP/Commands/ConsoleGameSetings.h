//
// Created by corvussharp on 22.11.22.
//

#ifndef LABOCHKAOOP_CONSOLEGAMESETINGS_H
#define LABOCHKAOOP_CONSOLEGAMESETINGS_H

#include "GameSettings.h"
class ConsoleGameSetings: public GameSettings{
public:
    void set_size() override;
    void set_output() override;
    void set_level() override;
    bool valid_arg(int a);
};


#endif //LABOCHKAOOP_CONSOLEGAMESETINGS_H
