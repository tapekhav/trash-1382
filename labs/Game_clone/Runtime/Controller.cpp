#include "Controller.h"

Controller::Controller(){
    model = Model();
    fieldView = FieldView(&model);
}

void Controller::createField(std::pair<int, int> size) {
    model.createField(size);
}

void Controller::notify(char& command) {
    model.movePlayerPosition(command);
}


