#ifndef LABS_MEDIATOR_H
#define LABS_MEDIATOR_H

#include "CommanderReader.h"
#include "Controller.h"

class Mediator {
public:
    Mediator() = default;

private:
    CommanderReader input;
    Controller game;
};

#endif //LABS_MEDIATOR_H
