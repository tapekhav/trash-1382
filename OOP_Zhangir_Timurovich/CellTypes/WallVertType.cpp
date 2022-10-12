
#include "WallVertType.h"

bool WallVertType::get_pass() {
    return this->pass;
}


WallVertType::WallVertType() {
    this->pass = true;
}