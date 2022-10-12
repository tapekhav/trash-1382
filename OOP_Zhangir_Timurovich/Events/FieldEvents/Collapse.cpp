//
// Created by roman on 11.10.2022.
//

#include "Collapse.h"


void Collapse::execute(void *obj) {
    if (obj) {
        auto *field = (Field *) obj;
        field->create_field();
    }
}
