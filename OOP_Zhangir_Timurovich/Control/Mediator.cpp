#include "Mediator.h"


void Mediator::start_game() {
    controller.create_field();
    controller.show_field();
    while(reader.set_move()){
        CommandReader::MOVES move = reader.get_move();
        controller.move_player(move);
        controller.show_field();
    }
}

Mediator::Mediator(Controller& controller, CommandReader& reader) {
    this->controller = controller;
    this->reader = reader;
};




