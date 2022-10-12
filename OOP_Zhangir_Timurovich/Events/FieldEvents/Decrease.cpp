//
// Created by roman on 12.10.2022.
//

#include "Decrease.h"

void Decrease::execute(void *obj) {
    if (obj) {
        auto *field = (Field *) obj;
        field->add_height(-5);
        field->add_width(-5);
    }
}
