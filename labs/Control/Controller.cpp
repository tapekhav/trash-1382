#include "Controller.h"

Controller::Controller() {
    int height = 0;
    int width = 0;

    while(height <= 0 || width <= 0) {
        height = Mediator().get_height();
        width = Mediator().get_width();
        std::cout << "Введите данные корректно!\n";
    }
    Field other(width, height);
    field = other;
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

