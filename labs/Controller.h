#ifndef LABS_CONTROLLER_H
#define LABS_CONTROLLER_H

#include "Player.h"
#include "Field.h"
#include "structs.h"
#include "FieldView.h"

class Controller {
public:
    explicit Controller();
    void move(STEP s);
    void start();

private:
    Field field;
};


#endif
