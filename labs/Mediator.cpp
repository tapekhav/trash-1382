#include "Mediator.h"
#include "ComandReader.h"
#include "Controller.h"
#include <typeinfo>

void Mediator::notify(MediatorObject &mediatorObject) {
    if(typeid(mediatorObject) == typeid(this->comandReader)){

    } else if (typeid(mediatorObject) == typeid(this->controller)){

    }
};

Mediator::Mediator() {
    this->comandReader = ComandReader();
    this->controller = Controller();
    this->controller.createField(this->comandReader.getFieldWidth(),
                                 this->comandReader.getFieldHeight(),
                                 this->comandReader.getPlayerPositionX(),
                                 this->comandReader.getPlayerPositionY());
    while(1){
        update();
    }
}


//вызывается внутри ComandReader с передачей экземпляра
//Mediator передает данные контроллеру вызовом соответсвующего метода

void Mediator::update(){
    this->comandReader.readInput();
    this->comandReader.getWay();
    //TODO проверить куда пошел player
    this->controller.setPlayerPosition(this->controller.getPlayerPositionX()+1, this->controller.getPlayerPositionY());
    this->controller.printFieldView();
}