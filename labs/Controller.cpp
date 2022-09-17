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

void Controller::start() {}

