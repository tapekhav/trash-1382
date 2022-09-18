#include "Mediator.h"

int Mediator::get_height() {
    input.read_height();
    return input.get_height();
}

int Mediator::get_width() {
    input.read_width();
    return input.get_width();
}

Player::STEP Mediator::get_step() {
    input.read_step();
    return input.get_step();
}
