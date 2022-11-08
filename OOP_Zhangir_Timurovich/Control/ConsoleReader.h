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

    MOVES read_move(LogOutInfo *info) override;

};
