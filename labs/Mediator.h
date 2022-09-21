#ifndef GAME_MEDIATOR_H
#define GAME_MEDIATOR_H


#include "MediatorObject.h"
#include "ComandReader.h"
#include "Controller.h"

class Mediator {
public:
    Mediator();
private:
    ComandReader comandReader;
    Controller controller;
    void notify(MediatorObject& mediatorObject);
    void update();
    void getFieldView() const;
};


#endif
