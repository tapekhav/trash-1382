#include "Mediator.h"

void Mediator::start() {
    this->reader = CommandReader();
    reader.set_size();
    this->controller = Controller(reader.get_width(), reader.get_height());
    this->active = true;
}

void Mediator::show_game() {
    controller.create_field();
    controller.show_field();
    if(this->active)
        while(reader.set_move()){
            CommandReader::MOVES move = reader.get_move();
            controller.move_player(move);
            controller.show_field();
        }
    else
        std::cout<<"controller is not active";
}

Mediator::Mediator() {
    this->active = false;
};




