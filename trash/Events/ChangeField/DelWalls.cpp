#include "DelWalls.h"

RuleDelWalls::RuleDelWalls(Field *field) {
    this->field = field;
}

void RuleDelWalls::execute() {
    field->delete_walls();
}
