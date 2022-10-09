#include <iostream>
#include "Controller.h"

Controller::Controller(std::pair<int, int> size): fieldView(FieldView(&model)), model(Model(size)){
    model.notify();
};

void Controller::notify(char& command) {
    model.movePlayerPosition(command);
}
