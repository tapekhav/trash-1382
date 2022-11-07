//
// Created by roman on 07.11.2022.
//

#ifndef MAIN_CPP_СOMMANDREADER_H
#define MAIN_CPP_СOMMANDREADER_H

#include <vector>
#include "../Info/Structs.h"

class CommandReader {
    virtual ~CommandReader() = default;

    virtual void set_size() = 0;

    virtual void set_output() = 0;

    virtual set_level() = 0;

    virtual [[nodiscard]] int get_width() const;

    virtual [[nodiscard]] int get_height() const;


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


#endif //MAIN_CPP_СOMMANDREADER_H
