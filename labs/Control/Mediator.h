#ifndef LABS_MEDIATOR_H
#define LABS_MEDIATOR_H

#include "CommandReader.h"
#include "Controller.h"

class Mediator {
public:
    Mediator() = default;
    int get_height();
    int get_width();
    Player::STEP get_step();
private:
    CommanderReader input;
};

#endif //LABS_MEDIATOR_H