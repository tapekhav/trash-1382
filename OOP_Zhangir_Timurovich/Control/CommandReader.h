//
// Created by roman on 07.11.2022.
//

#pragma once

#include <vector>
#include "../Info/Enums.h"
#include "ControlConfig/ControlConfig.h"
#include "../Logging/Subject.h"

class CommandReader : public Subject {
public:

    virtual ~CommandReader() = default;

    virtual void set_size() = 0;

    virtual void set_output() = 0;

    virtual void set_level() = 0;

    virtual int get_width() const;

    virtual int get_height() const;


    virtual MOVES read_move(LogOutInfo *info) = 0;

    virtual std::vector <LEVEL> get_levels();

    virtual std::vector <OUTPUT> get_outputs();

protected:
    int width{};
    int height{};
    std::vector <OUTPUT> outputs;
    std::vector <LEVEL> levels;
    ControlConfig *control_config;
};


