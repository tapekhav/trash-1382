#include <iostream>
#include "Mediator.h"
#include "CommandReader.h"
#include "Controller.h"

Mediator::Mediator(Controller& controller, CommandReader& commandReader) {
    this->controller = controller;
    this->commandReader = commandReader;
}

void Mediator::notify(MediatorObject &mediatorObject) {
    if(typeid(mediatorObject) == typeid(this->commandReader)){
        command = commandReader.getPlayerMove();
    }
    else if (typeid(mediatorObject) == typeid(this->controller)){
        controller.movePlayerPosition(command);
        controller.printFieldView();
    };
};

void Mediator::start() {
    controller.createField(
            commandReader.getFieldWidth(),
            commandReader.getFieldHeight());

    controller.printFieldView();

    while (update());
}


bool Mediator::update(){
    notify(commandReader);
    if (command == 'e') return false;
    notify(controller);
    return true;
}
