#include "WallHorType.h"

bool WallHorType::get_pass() {
    return this->pass;
}


WallHorType::WallHorType() {
    this->pass = true;
}