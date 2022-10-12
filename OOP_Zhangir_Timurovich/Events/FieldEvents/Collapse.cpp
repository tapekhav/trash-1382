//
// Created by roman on 11.10.2022.
//

#include "Collapse.h"


bool Collapse::execute(void *obj) {
    if (obj) {
        auto *field = (Field *) obj;
        field->create_field();
        return true;
    }
    return false;
}
