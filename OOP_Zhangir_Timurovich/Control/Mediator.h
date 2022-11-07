#pragma once

#include "Controller.h"
#include "ConsoleReader.h"

class Mediator {
public:
    Mediator(Controller& controller, ConsoleReader& reader);

    ~Mediator() = default;

    void start_game();

private:
    Controller controller;
    ConsoleReader reader;
};

