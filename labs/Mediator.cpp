#include "Mediator.h"
#include "CommandReader.h"
#include "Controller.h"

Mediator::Mediator(Controller& controller, CommandReader& commandReader) {
    this->commandReader = CommandReader();
    this->controller = Controller();
}

void Mediator::notify(MediatorObject &mediatorObject) {
    if(typeid(mediatorObject) == typeid(this->commandReader)){}
    else if (typeid(mediatorObject) == typeid(this->controller)){};
};

void Mediator::start() {
    controller.createField(
            commandReader.getFieldWidth(),
            commandReader.getFieldHeight());

    controller.printFieldView();

    char input = ' ';
    while (update(input));
}

bool Mediator::update(char& input){
    commandReader.getPlayerMove(input);
    if (input == 'e') return false;
    controller.movePlayerPosition(input);
    controller.printFieldView();
    return true;
}
