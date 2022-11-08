#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "../Info/Enums.h"
#include "../Info/LogOutInfo.h"
#include "../Logging/Subject.h"
#include "../Info/Enums.h"
#include "ControlConfig/ControlConfig.h"
#include "CommandReader.h"

class ConsoleReader : public CommandReader {
public:

    explicit ConsoleReader(ControlConfig *cfg = nullptr);

    ~ConsoleReader() override = default;

    void set_size() override;

    void set_output() override;

    void set_level() override;

//    [[nodiscard]] int get_width() const;
//
//    [[nodiscard]] int get_height() const;


    MOVES read_move(LogOutInfo *info) override;

//    std::vector <LEVEL> get_levels();

//    std::vector <OUTPUT> get_outputs();


//private:
//    int width{};
//    int height{};
//    std::vector <OUTPUT> outputs;
//    std::vector <LEVEL> levels;
//    ControlConfig *control_config;
};
