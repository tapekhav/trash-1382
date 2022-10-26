//
// Created by roman on 11.10.2022.
//

#include "Collapse.h"

Collapse::Collapse(Field *field, Player* player){
    this->player = player;
    this->field = field;
}

bool Collapse::execute() {
    if (field) {
        field->create_field(this->player);
        Message message(GAME, "Event happened");
        notify(message);
        return true;
    }
    return false;
}