#include "Increase.h"

void Increase::execute(void *obj) {
    if (obj) {
        auto *field = (Field *) obj;
        field->add_height(5);
        field->add_width(5);
    }
}
