#include "Controller.h"


void Controller::createField(unsigned int width, unsigned int height) {
    field = Field(width, height);
    fieldView.initialize(&field);
}

void Controller::movePlayerPosition(char c) {
    Player::STEP s;
    switch (c) {
        case 'w':
            s = Player::UP;
            break;
        case 's':
            s = Player::DOWN;
            break;
        case 'a':
            s = Player::LEFT;
            break;
        case 'd':
            s = Player::RIGHT;
            break;
        default:
            s = Player::NOTHING;
            break;
    }
    field.movePlayer(s);
}

void Controller::printFieldView() const{
    fieldView.printFieldView();
}

Controller &Controller::operator=(const Controller &other) {
    this->field = other.field;
    this->player = other.player;
    this->fieldView = other.fieldView;
    return *this;
}

void Controller::start() {

}

