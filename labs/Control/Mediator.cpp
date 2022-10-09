#include "Mediator.h"

void Mediator::start() {
    Player player;
    input.read_char();

    if (input.get_char() != 'y') {
        input.read_size();
        game.set_field(input.get_width(), input.get_height());
    } else {
        game.set_field_standard();
    }

    while(input.get_step() != Player::EXIT) {
        game.show_field();
        input.read_step();
        game.set_step(input.get_step(), player);
    }
}
