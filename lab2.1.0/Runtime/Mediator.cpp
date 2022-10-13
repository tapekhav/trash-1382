#include <iostream>
#include "Mediator.h"

Mediator::Mediator():
    commandReader(CommandReader()),
    controller(Controller(std::pair<int, int>({commandReader.getFieldWidth(), commandReader.getFieldHeight()}))){};


void Mediator::notify(MediatorObject &mediatorObject) {
    if(typeid(mediatorObject) == typeid(this->commandReader)){
        commandReader.notify(command);
    }
    else if (typeid(mediatorObject) == typeid(this->controller)){
        controller.notify(command);
    };
};

void Mediator::start() {
    help();
    while (update());
}

void Mediator::help() const {
    std::string data = "Use \"wasd\" keys to move\t\"e\" for exit game\n";
    std::cout << data;
}


bool Mediator::update(){
    notify(commandReader);
    if (command == 'e') return false;
    if (command == 'h') help();
    notify(controller);
    return !controller.isEndGame();
}
