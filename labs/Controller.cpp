#include "Controller.h"

void Controller::createField(unsigned int width, unsigned int height, unsigned playerPositionX, unsigned int playerPositionY) {
    this->field = Field(width, height, playerPositionX, playerPositionY);
}

void Controller::setPlayerPosition(unsigned int playerPositionX, unsigned int playerPositionY) {
    this->field.setPlayerPosition(playerPositionX, playerPositionY);
}

unsigned int Controller::getPlayerPositionX() const {
    return this->field.getPlayerPositionX();
}

unsigned int Controller::getPlayerPositionY() const {
    return this->field.getPlayerPositionY();
}

void Controller::printFieldView() const {
    this->fieldView.print(this->field);
}
