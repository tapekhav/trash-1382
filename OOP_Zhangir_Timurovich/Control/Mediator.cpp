#include "Mediator.h"
#include "../Logging/logs/StatusObserver.h"

void Mediator::start_game() {
    new StatusObserver(&(this->controller));
    new StatusObserver(&(this->reader));
    bool res = true;
    bool mv = true;
    controller.create_field();
    controller.show_field();
    while (mv && res) {
        mv = reader.set_move(controller.get_info());
        CommandReader::MOVES move = reader.get_move();
        res = controller.move_player(move);
        controller.show_field();
    }
}

Mediator::Mediator(Controller &controller, CommandReader &reader) {
    this->controller = controller;
    this->reader = reader;
};




