#ifndef LABS_MEDIATOR_H
#define LABS_MEDIATOR_H

#include "CommanderReader.h"
#include "Controller.h"

class Mediator {
public:
    explicit Mediator(CommanderReader inp);
private:
    CommanderReader input;
};

#endif //LABS_MEDIATOR_H
