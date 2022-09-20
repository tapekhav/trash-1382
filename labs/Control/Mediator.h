#ifndef LABS_MEDIATOR_H
#define LABS_MEDIATOR_H

#include "CommandReader.h"
#include "Controller.h"

class Mediator {
public:
    Mediator() = default;
    void start();
private:
    CommandReader input;
    Controller game;
};

#endif //LABS_MEDIATOR_H