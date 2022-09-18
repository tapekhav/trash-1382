#include "Controller.h"

Controller::Controller() : field(Field(Mediator().get_width(), Mediator().get_height())) {
    field.make_field();
    FieldView field_view(field);
    field_view.print();
}

void Controller::move(Player::STEP s) {
    field.change_player_pos(s);
    FieldView field_view(field);
    field_view.print();
}

void Controller::start() {
    Player::STEP step;
    while(true) {
        step = Mediator().get_step();
        if (step == Player::EXIT)
            break;
        move(step);
    }
}

