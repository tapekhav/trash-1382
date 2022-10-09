#include <iostream>
#include "Mediator.h"

Mediator::Mediator(): commandReader(CommandReader()), controller(Controller(std::pair<int, int>({commandReader.getFieldHeight(), commandReader.getFieldWidth()}))){};


void Mediator::notify(MediatorObject &mediatorObject) {
    if(typeid(mediatorObject) == typeid(this->commandReader)){
        commandReader.notify(command);
    }
    else if (typeid(mediatorObject) == typeid(this->controller)){
        controller.notify(command);
    };
};

void Mediator::start() {
    //controller.createField(std::pair<int, int> {commandReader.getFieldWidth(), commandReader.getFieldHeight()});
    while (update());
}


bool Mediator::update(){
    notify(commandReader);
    if (command == 'e') return false;
    if (command == 'h') std::cout << help << '\n';
    notify(controller);
    return true;
}
