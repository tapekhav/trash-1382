//
// Created by roman on 12.10.2022.
//

#include "Decrease.h"

Decrease::Decrease(Field *field, Player* player){
    this->player = player;
    this->field = field;
}

bool Decrease::execute() {
    if (field) {
        field->add_height(-5);
        field->add_width(-5);
        return true;
    }
    return false;
}
