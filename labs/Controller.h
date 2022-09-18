#ifndef LABS_CONTROLLER_H
#define LABS_CONTROLLER_H

#include "Player.h"
#include "Field.h"
#include "FieldView.h"
#include "Mediator.h"

class Controller {
public:
    explicit Controller();
    void move(Player::STEP s);
    void start();
private:
    Field field;
};


#endif
