//
// Created by roman on 11.10.2022.
//

#include "Collapse.h"

Collapse::Collapse(Field *field, Player* player){
    this->player = player;
    this->field = field;
}

bool Collapse::execute(LogOutInfo* info) {
    if (field) {
        field->create_field(this->player);
        Message message(GAME, "Collapse event happened", info);
        notify(message);
        return true;
    }
    return false;
}