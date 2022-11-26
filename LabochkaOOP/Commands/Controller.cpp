//
// Created by corvussharp on 21.09.22.
//

#include "Controller.h"
#include "../LOG/Logs/LogsLvlErrors.h"
#include "../INPUT/ControlConfig.h"

Controller::Controller() : field(Field(10, 10)), field_view(field) {

    new LogsLvlGame(&this->field);
    new LogsLvlGame(&this->person);
    new LogsLvlErrors(&this->field);
}

void Controller::set_field(int w, int h) {
    field = Field(w, h);
    field.make_field();
}

void Controller::set_field_base() {
    field = Field();
    field.make_field();
}

void Controller::set_step(CONTROL step) {
    field.change_person_pos(step);
}


void Controller::print_stats() {
    std::cout << "HP: " << field.get_person().get_hp() << " DMG: " << field.get_person().get_dmg() << " XP: "
              << field.get_person().get_xp()
              << " Lvl: " << field.get_person().get_lvl() << std::endl;
}

void Controller::print_field() {
    field_view = FieldView(field);
    field_view.print();
}

bool Controller::death_person() {
    if (field.get_person().get_hp() < 1) return true;
    return false;
}

bool Controller::win_game() {
    if (field.get_win()) {
        Message message(STATUS, "Game Win");
        LOG.print(message);
        return true;
    }
    return false;
}



