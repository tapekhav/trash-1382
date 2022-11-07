#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "../Info/Structs.h"
#include "../Info/LogOutInfo.h"
#include "../Logging/Subject.h"
#include "../Logging/Subject.h"
#include "../Info/Structs.h"
#include "ControlConfig/ControlConfig.h"

class ConsoleReader : public Subject {
public:

    explicit ConsoleReader(ControlConfig *cfg = nullptr);

    ~ConsoleReader() override = default;

    void set_size();

    void set_output();

    void set_level();

    [[nodiscard]] int get_width() const;

    [[nodiscard]] int get_height() const;


    MOVES read_move(LogOutInfo *info);

    std::vector <LEVEL> get_levels();

    std::vector <OUTPUT> get_outputs();


private:
    int width{};
    int height{};
    std::vector <OUTPUT> outputs;
    std::vector <LEVEL> levels;
    ControlConfig *control_config;
};
