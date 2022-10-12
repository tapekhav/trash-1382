#include "Mediator.h"


void Mediator::start_game() {
    bool res = true;
    bool mv = true;
    controller.create_field();
    controller.show_field();
    while (mv && res) {
        mv = reader.set_move();
        CommandReader::MOVES move = reader.get_move();
        res = controller.move_player(move);
//        if(res)
        controller.show_field();
    }
}

Mediator::Mediator(Controller &controller, CommandReader &reader) {
    this->controller = controller;
    this->reader = reader;
};




