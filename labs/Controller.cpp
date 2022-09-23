#include "Controller.h"

void Controller::createField(unsigned int width, unsigned int height) {
    this->field = Field(width, height);
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
    }
    this->field.movePlayer(s);
}

void Controller::printFieldView() const{
    this->fieldView.print(this->field);
}
