#ifndef LABS_CONTROLLER_H
#define LABS_CONTROLLER_H

#include "../Background/FieldView.h"

class Controller {
public:
    Controller();

    void set_field(int width, int height);
    void set_field_standard();
    void set_step(Player::STEP step, Player& player);

    void show_field();
private:
    Field field;
    FieldView field_view;
};


#endif