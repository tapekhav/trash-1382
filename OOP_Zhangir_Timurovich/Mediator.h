#pragma once

#include "Controller.h"
#include "CommandReader.h"

class Mediator {
public:
    Mediator();

    ~Mediator() = default;

    void start();

    void show_game();

private:
    Controller controller;
    CommandReader reader;
    bool active;
};

