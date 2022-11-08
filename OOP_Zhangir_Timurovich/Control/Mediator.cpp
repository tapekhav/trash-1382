#include "Mediator.h"
#include "../Logging/logs/StatusObserver.h"
#include "../Info/Enums.h"

void Mediator::start_game() {
    new StatusObserver(&(this->controller));
    new StatusObserver(this->reader);
    bool res = true;
    MOVES mv = NOWHERE;
    controller.create_field();
    controller.show_field();
    while (mv != EXIT && res) {
        mv = reader->read_move(controller.get_info());
        res = controller.move_player(mv);
        controller.show_field();
    }
}

Mediator::Mediator(Controller &controller, CommandReader* reader) {
    this->controller = controller;
    this->reader = reader;
};




