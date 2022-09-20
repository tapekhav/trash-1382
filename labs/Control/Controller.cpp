#include "Controller.h"


Controller::Controller() : field(Field()), field_view(FieldView(field)) {}

void Controller::set_field(int width, int height) {
    field = Field(width, height);
    field.make_field();
}

void Controller::set_field_standard() {
    field = Field();
    field.make_field();
}

void Controller::set_step(Player::STEP step) {
    field.change_player_pos(step);
}

void Controller::show_field() {
    field_view = FieldView(field);
    field_view.print();
}
