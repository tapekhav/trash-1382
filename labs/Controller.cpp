#include "Controller.h"

Controller::Controller() : field(Field(20, 10)), player() {
    field.make_field();
    FieldView field_view(field);
    field_view.print();
}

void Controller::move(STEP s) {
    field.change_player_pos(s);
    FieldView field_view(field);
    field_view.print();
}

void Controller::start() {
    STEP step;
    while(true) {
        int i;
        std::cin >> i;

        switch (i) {
            case 1:
                step = UP;
                break;
            case 2:
                step = DOWN;
                break;
            case 3:
                step = RIGHT;
                break;
            case 4:
                step = LEFT;
                break;
            default:
                return;
        }

        move(step);
    }
}

