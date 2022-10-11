//
// Created by roman on 11.10.2022.
//

#include "Collapse.h"


void Collapse::execute(void *obj) {
    auto* field = (Field*) obj;
    if (field) {
        field->create_field();
    }
}
