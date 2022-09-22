#include "Controller.h"
#include "CommandReader.h"

Controller::Controller(int width, int height, int health, int armour, int
damage) {
    this->player = Player(health, armour, damage);
    this->field = new Field(width, height);
    this->view = FieldView(this->field);
}
Controller::~Controller(){
    delete [] field;
};

void Controller::show_field() {
    this->view.show_field();
}

void Controller::create_field(){
    this->field->create_field();
}

void Controller::move_player(CommandReader::MOVES move) {
    int x = 0;
    int y = 0;
    switch (move) {
        case CommandReader::MOVES::LEFT:
            x -= 1;
            break;
        case CommandReader::MOVES::RIGHT:
            x += 1;
            break;
        case CommandReader::MOVES::UP:
            y -= 1;
            break;
        case CommandReader::MOVES::DOWN:
            y += 1;
            break;
        case CommandReader::MOVES::NOWHERE:
            return;
    }
    field->move_player(x, y);
    view.show_field();
}


