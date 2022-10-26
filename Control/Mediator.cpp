#include "Mediator.h"

Mediator::Mediator() {
    error_log = new ErrorLog(&input);
}

Mediator::~Mediator() {
    delete error_log;
}

void Mediator::start() {
    input.read_char();

    if (input.get_char() != 'y') {
        input.read_size();
        game.set_field(input.get_width(), input.get_height());
    } else {
        game.set_field_standard();
    }

    while(input.get_step() != Player::EXIT && game.get_status() == GameStatus::ON) {
        input.read_step();
        game.set_step(input.get_step());

        game.check_win_game();
        game.check_end_game();
    }
}
