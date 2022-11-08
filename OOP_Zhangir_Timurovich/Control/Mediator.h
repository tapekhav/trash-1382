#pragma once

#include "Controller.h"
#include "ConsoleReader.h"

class Mediator {
public:
    Mediator(Controller& controller, CommandReader* reader);

    ~Mediator() = default;

    void start_game();

private:
    Controller controller;
    CommandReader* reader;
};

