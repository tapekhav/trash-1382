#include "NewLevel.h"

NewLevel::NewLevel(Field *field) {
    this->field = field;
}

void NewLevel::execute() {
    field->generate_walls();
}
