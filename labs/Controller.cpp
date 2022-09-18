#include "Controller.h"

Controller::Controller() : field(Field(20, 10)) {
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
        int i;
        std::cin >> i;

        switch (i) {
            case 1:
                step = Player::UP;
                break;
            case 2:
                step = Player::DOWN;
                break;
            case 3:
                step = Player::RIGHT;
                break;
            case 4:
                step = Player::LEFT;
                break;
            default:
                return;
        }

        move(step);
    }
}

